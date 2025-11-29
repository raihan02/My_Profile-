const { onRequest } = require("firebase-functions/v2/https");

const { initializeApp } = require("firebase-admin/app");

const { getMessaging } = require("firebase-admin/messaging");

const axios = require("axios");



initializeApp();



exports.checkVideoStatus = onRequest(

  {

    timeoutSeconds: 1080, // ✅ 18 minutes

    memory: "256MiB",

  },

  async (req, res) => {

    const { type, video_id, fcm_token, second, api_call_interval, attempt = 1 } = req.body;



    if (attempt > 80) {

      console.log("❌ Max attempts reached");

      return res.status(200).send({ message: "Max attempts reached" });

    }



    let apiUrl = "";

    let headers = {

      Authorization: "Bearer user:1252-xTa1L7hMZFVoQs3SPGi4"

    };



    // -----------------------

    // 1️⃣ Select API URL

    // -----------------------

    if (type === "pixverse") {

      apiUrl = `https://api.useapi.net/v2/pixverse/videos/${video_id}`;

    } else if (type === "hailuo") {

      apiUrl = `https://api.useapi.net/v1/minimax/videos/${video_id}`;

    } else if (type === "veo") { // ⭐ VEO Logic Start

      apiUrl = `https://api.useapi.net/v1/google-flow/jobs/${video_id}`;

    } else { // ⭐ Invalid type for any other type

      return res.status(400).send({ error: "Invalid type" });

    }



    try {

      const response = await axios.get(apiUrl, { headers });

      const data = response.data;



      let isCompleted = false;



      // -----------------------

      // 2️⃣ COMPLETION LOGIC

      // -----------------------

      if (type === "pixverse") {

        isCompleted = data.video_status_name === "COMPLETED" && data.video_status_final === true;

      } else if (type === "hailuo") {

        isCompleted = data.statusLabel === "completed" && data.statusFinal === true;

      } else if (type === "veo") { // ⭐ VEO Completion Logic Added

        const jobStatus = data.status; 

        const operations = data.response?.operations ?? [];

        const firstOp = operations[0];



        const opStatus = firstOp?.status; 

        const videoMeta = firstOp?.operation?.metadata?.video;

        const fifeUrl = videoMeta?.fifeUrl;

        

        // VEO-এর জন্য কমপ্লিশন চেক (ভিডিও URL অনুপস্থিত থাকলেও এখানে isCompleted true হবে)

        isCompleted =

          jobStatus === "completed" &&

          opStatus === "MEDIA_GENERATION_STATUS_SUCCESSFUL"; // URL চেক বাদ দেওয়া হলো

      }



      console.log(`🔁 Attempt #${attempt} | Type: ${type} | Completed: ${isCompleted}`); 



      // ----------------------------------------------------

      // 3️⃣ If COMPLETED → Send Push Notification

      // ----------------------------------------------------

      if (isCompleted) {

        const msg = {

          token: fcm_token,

          notification: {

            title: "Your AI-generated video is ready!",

            body: "Tap to watch it now.",

          },

          apns: {

            payload: {

              aps: {

                sound: "default"

              }

            }

          },

          data: {

            video_id,

            type,

            status: "completed"

          }

        };



        await getMessaging().send(msg);

        console.log("✅ Push sent");

        return res.status(200).send({ message: "Notification sent" });

      } else {

        console.log("⏳ Not ready yet, retrying...");



        setTimeout(async () => {

          await axios.post("https://us-central1-ai-video-65e40.cloudfunctions.net/checkVideoStatus", {

            type,

            video_id,

            fcm_token,

            second,

            api_call_interval,

            attempt: attempt + 1,

          });

        }, api_call_interval * 1000);



        return res.status(200).send({ message: "Waiting, next attempt scheduled" });

      }



    } catch (error) {

      console.error("❌ Error:", error.response?.data || error.message);

      return res.status(500).send({

        error: "API request failed",

        details: error.response?.data || error.message

      });

    }

  }

);
