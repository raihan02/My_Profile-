#include <bits/stdc++.h>
#include<stdio.h>
#include<graphics.h>
#define pi acos(-1.0)
#define cos(a) (cos(a*pi/180.0))
#define sin(a) (sin(a*pi/180.0))
#define tan(a) (tan(a*pi/180.0))
using namespace std;

double x,y,x3,y3,x4,y4,dx,dy,pixel;
int inside=0;// 0000
int leftt=1;  // 0001
int rightt=2; // 0010
int bottomm=4;// 0100
int topp=8;   // 1000
double xmin,ymin,xmax,ymax;
int k,arrx[50],arry[50];
float m;
void clipl(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 >= xmin && x2 >= xmin)
    {
        arrx[k]=x2;
        arry[k]=y2;
        k+=1;
    }
    if(x1 < xmin && x2 >= xmin)
    {
        arrx[k]=xmin;
        arry[k]=y1+m*(xmin-x1);
        arrx[k+1]=x2;
        arry[k+1]=y2;
        k+=2;
    }
    if(x1 >= xmin  && x2 < xmin)
    {
        arrx[k]=xmin;
        arry[k]=y1+m*(xmin-x1);
        k+=1;
    }
}
void clipt(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 <= ymax && y2 <= ymax)
    {
        arrx[k]=x2;
        arry[k]=y2;
        k+=1;
    }
    if(y1 > ymax && y2 <= ymax)
    {
        arrx[k]=x1+m*(ymax-y1);
        arry[k]=ymax;
        arrx[k+1]=x2;
        arry[k+1]=y2;
        k+=2;
    }
    if(y1 <= ymax  && y2 > ymax)
    {
        arrx[k]=x1+m*(ymax-y1);
        arry[k]=ymax;
        k+=1;
    }
}

void clipr(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 <= xmax && x2 <= xmax)
    {
        arrx[k]=x2;
        arry[k]=y2;
        k+=1;
    }
    if(x1 > xmax && x2 <= xmax)
    {
        arrx[k]=xmax;
        arry[k]=y1+m*(xmax-x1);
        arrx[k+1]=x2;
        arry[k+1]=y2;
        k+=2;
    }
    if(x1 <= xmax  && x2 > xmax)
    {
        arrx[k]=xmax;
        arry[k]=y1+m*(xmax-x1);
        k+=1;
    }
}

void clipb(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 >= ymin && y2 >= ymin)
    {
        arrx[k]=x2;
        arry[k]=y2;
        k+=1;
    }
    if(y1 < ymin && y2 >= ymin)
    {
        arrx[k]=x1+m*(ymin-y1);
        arry[k]=ymin;
        arrx[k+1]=x2;
        arry[k+1]=y2;
        k+=2;
    }
    if(y1 >= ymin  && y2 < ymin)
    {
        arrx[k]=x1+m*(ymin-y1);
        arry[k]=ymin;
        k+=1;
    }
}

void sutherland_Hodgman_polygon_clipping()
{
    int gd,gm,n,i,poly[50],polyy[50],polyx[50];
    cout<<"Enter the coordinates of rectangular clip window :\n(xmin,ymin)and (xmax,ymax ): ";
    cin>>xmin>>ymin>>xmax>>ymax;
    cout<<"\nNumber of sides of the polygon : ";
    cin>>n;
    cout<<"Enter the coordinates of the polygon:\n";
    for( i=0; i<n; i++)
    {
        cin>>polyx[i]>>polyy[i];
        poly[2*i]=polyx[i];
        poly[2*i+1]=polyy[i];
    }
    polyx[i]=polyx[0];
    polyy[i]=polyy[0];
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    setcolor(YELLOW);
    rectangle(xmin,ymin,xmax,ymax);
    cout<<"Polygon before clipping\n";
    fillpoly(n,poly);
    getch();
    cleardevice();
    k=0;
    for(i=0; i < n; i++)
        clipl(polyx[i],polyy[i],polyx[i+1],polyy[i+1]);
    n=k;
    for(i=0; i < k; i++)
    {
        polyx[i]=arrx[i];
        polyy[i]=arry[i];
    }
    polyx[i]=polyx[0];
    polyy[i]=polyy[0];
    k=0;
    for(i=0; i < n; i++)
        clipt(polyx[i],polyy[i],polyx[i+1],polyy[i+1]);
    n=k;
    for(i=0; i < k; i++)
    {
        polyx[i]=arrx[i];
        polyy[i]=arry[i];
    }
    polyx[i]=polyx[0];
    polyy[i]=polyy[0];
    k=0;
    for(i=0; i < n; i++)
        clipr(polyx[i],polyy[i],polyx[i+1],polyy[i+1]);
    n=k;
    for(i=0; i < k; i++)
    {
        polyx[i]=arrx[i];
        polyy[i]=arry[i];
    }
    polyx[i]=polyx[0];
    polyy[i]=polyy[0];
    k=0;
    for(i=0; i < n; i++)
        clipb(polyx[i],polyy[i],polyx[i+1],polyy[i+1]);
    for(i=0; i < k; i++)
    {
        poly[2*i]=arrx[i];
        poly[2*i+1]=arry[i];
    }
    cout<<"Polygon before clipping\n";
    setcolor(GREEN);
    rectangle(xmin,ymin,xmax,ymax);
    if(k)
        fillpoly(k,poly);
    getch();
    closegraph();
}
int check_point(double x, double y)// check each point for clipping rectangle
{
    int position_point=inside;
    if(x < xmin)
        position_point = leftt;
    else if(x > xmax)
        position_point = rightt;
    if(y < ymin)
        position_point |= bottomm;
    else if(y > ymax)
        position_point |= topp;
    return position_point;
}
void cohen_line_clip(double x0, double y0, double x1, double y1)
{
    int position0 = check_point(x0, y0);// line from (x0,y0) to (x1,y1)
    int position1 = check_point(x1, y1);
    bool draw = 0;
    while (1)
    {
        if(!(position0 || position1))// full line is inside
        {
            draw = 1;
            break;
        }
        else if(position0 && position1)//full line is outside
        {
            break;
        }
        else
        {
            // portion of  line is inside & at least one point is outside
            double x, y;
            int out_point;
            if(position0)
            {
                out_point=position0;
            }
            else
            {
                out_point=position1;
            }
            if(out_point & topp)// point is in top
            {
                x = x0+(x1-x0)*(ymax-y0)/(y1-y0);
                y = ymax;
            }
            else if(out_point & bottomm)// point is in bottom
            {
                x = x0+(x1-x0)*(ymin-y0)/(y1-y0);
                y = ymin;
            }
            else if(out_point & rightt)// point is in right
            {
                y = y0+(y1-y0)*(xmax-x0)/(x1-x0);
                x = xmax;
            }
            else if(out_point & leftt)// point is in left
            {
                y = y0+(y1-y0)*(xmin-x0)/(x1-x0);
                x = xmin;
            }
            if(out_point == position0)//new point for outpoint
            {
                x0 = x;
                y0 = y;
                position0 = check_point(x0, y0);
            }
            else
            {
                x1 = x;
                y1 = y;
                position1 = check_point(x1, y1);
            }
        }//repeat loop until outpoint is come to the window
    }
    if(draw)//line segment within the window.
    {
        line(x0, y0, x1, y1);
    }
}
void cohen_line_clip()
{
    int gd,gm;
    cout<<"Enter window points (xmin,ymin) & (xmax,ymax):\n";
    cin>>xmin>>ymin>>xmax>>ymax;
    double rx0,ry0,rx1,ry1;
    cout<<"Enter rectangle point (rx0,ry0) & (rx1,ry1):\n";
    cin>>rx0>>ry0>>rx1>>ry1;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    line(xmin,ymin,xmax,ymin);
    line(xmin,ymin,xmin,ymax);
    line(xmax,ymin,xmax,ymax);
    line(xmin,ymax,xmax,ymax);
    cohen_line_clip(rx0,ry0,rx1,ry0);
    cohen_line_clip(rx0,ry0,rx0,ry1);
    cohen_line_clip(rx1,ry0,rx1,ry1);
    cohen_line_clip(rx0,ry1,rx1,ry1);
    getch();
    closegraph();

}
/*Input & Output
Enter window points (xmin,ymin) & (xmax,ymax):
50 50 200 200
Enter rectangle point (rx0,ry0) & (rx1,ry1):
100 25 300 150
*/
void draw_rect(double x1,double y1,double x2,double y2,int c)
{
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dx>=dy)
        pixel=dx;
    else
        pixel=dy;
    dx=dx/pixel;
    dy=dy/pixel;
    x=x1;
    y=y1;
    int i=1;
    while(i<=pixel)
    {
        putpixel(x,y,c);
        x=x+dx;
        y=y+dy;
        i=i+1;
        delay(5);
    }
}
void bb(int x1,int y1,int r)
{
    int d = 3-2*r;
    int x=0,y=r;
    for (int x = 0; x <= y; x++)
    {
        putpixel(x1+x,y1+y,4);
        delay(10);
        putpixel(x1-y,y1-x,4);
        delay(10);
        putpixel(x1+y,y1-x,4);
        delay(10);
        putpixel(x1-y,y1+x,4);
        delay(10);
        putpixel(x1+y,y1+x,4);
        delay(10);
        putpixel(x1-x,y1-y,4);
        delay(10);
        putpixel(x1+x,y1-y,4);
        delay(10);
        putpixel(x1-x,y1+y,4);
        delay(10);
        if(d<=0)
        {
            d+=4*x+6;
        }
        else
        {
            d+=4*x-4*y-10;
            y-=1;
        }
    }
}
void national_flag( )
{
    double a,b,c,d,h,w;
    int gd,gm,cnt=0,cnt2=0;
    cout<<"Enter the value of x & y: ";
    cin>>a>>b;
    printf("Enter the value of Height: ");
    cin>>h; w=int((h/6)*10);
    float x1, y1, x2, y2,r;
    x1=a+(int)w/2;y1=b+(int)h/2;r=(int)w/5;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    draw_rect(a,b,a+w,b,2);
    draw_rect(a,b,a,b+h,2);
    draw_rect(a,b+h,a+w,b+h,2);
    draw_rect(a+w,b,a+w,b+h+1,2);
    bb(x1,y1,r);
    a=a-4;b=b-4;
    w=3;h=h+80;
    draw_rect(a,b,a+w,b,6);
    draw_rect(a,b,a,b+h,6);
    draw_rect(a,b+h,a+w,b+h,6);
    draw_rect(a+w,b,a+w,b+h+1,6);
    getch();
    closegraph();
}
void dda()
{
     double x1,y1,x2,y2,dx,dy,xin,yin,step,x,y;
    printf("Enter two end points:(x1,y1) and (x2,y2):\n");
    scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    dx=x2-x1;
    dy=y2-y1;
    if(dx>=dy)
    {
        step=dx;
    }
    else
    {
        step=dy;
    }
    xin=dx/step;
    yin=dy/step;
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    x=x1;
    y=y1;
    for(int i=1; i<=step; i++)
    {
        putpixel(x,y,6);
        delay(15);
        x=x+xin;
        y=y+yin;
    }
    getch();
    return;
}
void bresenham(int x1, int y1, int x2, int y2)
{
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    int m_new = 2 * (y2 - y1);
    int slope_error_new = m_new- 2*(x2 - x1);
    for (int x = x1, y = y1; x <= x2; x++)
    {

        putpixel(x,y,6);
        delay(10);

        slope_error_new += m_new;

        if (slope_error_new >= 0)
        {
            y++;
            slope_error_new  -= 2 * (x2 - x1);
        }
    }
}

// driver function
void bresenham_line()
{
    float x1, y1, x2, y2;
    printf("Enter the value of x1 : ");
    scanf("%f",&x1);
    printf("Enter the value of y1 : ");
    scanf("%f",&y1);
    printf("Enter the value of x2 : ");
    scanf("%f",&x2);
    printf("Enter the value of y1 : ");
    scanf("%f",&y2);
    if(x1>x2&&y1>y2){
        swap(x1,x2);
        swap(y1,y2);
        }
    if(x1<x2&&y1<y2)
    bresenham(x1, y1, x2, y2);
    else cout<<"Not Possible\n";
    getch();
    return;
}
void bresenham_circle()
{
    double d,r,x,y,xc,yc;
    printf("Enter center and radius:(xc,yc) and r:\n");
    scanf("%lf %lf %lf",&xc,&yc,&r);
    d=3-2*r;
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    x=0;
    y=r;
    while(x<=y)
    {
        putpixel(xc+x,yc+y,1);
        delay(15);
        putpixel(xc+x,yc-y,2);
        delay(15);
        putpixel(xc-x,yc+y,3);
        delay(15);
        putpixel(xc-x,yc-y,4);
        delay(15);
        putpixel(xc+y,yc+x,6);
        delay(15);
        putpixel(xc+y,yc-x,7);
        delay(15);
        putpixel(xc-y,yc+x,8);
        delay(15);
        putpixel(xc-y,yc-x,10);
        delay(15);
        if(d<=0)
        {
            d+=4*x+6;
        }
        else
        {
            d+=4*x-4*y+10;
            y--;
        }
        x++;
    }
    getch();
    return;
}
void mp_ellipse(double xc,double yc,double rx,double ry){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    double x,y,p;
    x=0;
    y=ry;
    p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
    while((2*x*ry*ry)<(2*y*rx*rx))
    {
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        if(p<0)
        {
            x=x+1;
            p=p+(2*ry*ry*x)+(ry*ry);
        }
        else
        {
            x=x+1;
            y=y-1;
            p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
        }
    }
    p=(x+0.5)*(x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;

    while(y>=0)
    {
        putpixel(xc+x,yc-y,1);
        putpixel(xc-x,yc+y,4);
        putpixel(xc+x,yc+y,6);
        putpixel(xc-x,yc-y,9);

        if(p>0)
        {
            y=y-1;
            p=p-(2*rx*rx*y)+(rx*rx);
        }
        else
        {
            y=y-1;
            x=x+1;
            p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
        }
    }
    getch();

}
void ellipse()
{
    double x,y,p,xc,yc,rx,ry;
    printf("Enter (xc,yc) and a, b:");
    scanf("%lf %lf %lf %lf",&xc,&yc,&rx,&ry);
    mp_ellipse(xc,yc,rx,ry);

}
void transformxx()
{
    double a,b,c,d,h,w,sx,sy,cx,cy,theta,dx,dy;
    int gd,gm;
    cout<<"Enter the value of initial point (x,y): ";
    cin>>a>>b;
    printf("Enter the value of Width & Height: ");
    cin>>w>>h;
    cout<<"For translation. Enter Cx and Cy:\n";
    cin>>cx>>cy;
    cout<<"For rotation. Enter Theta:\n";
    cin>>theta;
    cout<<"For Scaling. Enter Sx & Sy:\n";
    cin>>sx>>sy;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    line(a,b,a+w,b);//Original Rectangle
    delay(200);
    line(a,b,a,b+h);
    delay(200);
    line(a,b+h,a+w,b+h);
    delay(200);
    line(a+w,b,a+w,b+h);
    delay(200);
    if((a+cx)<0||(b+cy)<0)//After Translation
    {
        cout<<"Out of boundary.\n";
    }
    else
    {
        a+=cx;
        b+=cy;
        line(a,b,a+w,b);
        delay(200);
        line(a,b,a,b+h);
        delay(200);
        line(a,b+h,a+w,b+h);
        delay(200);
        line(a+w,b,a+w,b+h);
        delay(200);
    }
    int x0,y0,x1,y1,x2,y2,x3,y3;
    w=w*sx;
    h=h*sy;
    x0=(a)*cos(theta)-b*sin(theta);
    y0=(a)*sin(theta)+b*cos(theta);
    x1=(a+w)*cos(theta)-b*sin(theta);
    y1=(a+w)*sin(theta)+b*cos(theta);
    x2=(a)*cos(theta)-(b+h)*sin(theta);
    y2=(a)*sin(theta)+(b+h)*cos(theta);
    x3=(a+w)*cos(theta)-(b+h)*sin(theta);
    y3=(a+w)*sin(theta)+(b+h)*cos(theta);
    dx=a-x0;
    dy=b-y0;
    x0=x0+dx;
    y0=y0+dy;
    x1=x1+dx;
    y1=y1+dy;
    x2=x2+dx;
    y2=y2+dy;
    x3=x3+dx;
    y3=y3+dy;
    line(x0,y0,x1,y1);//After Translation, Rotation and Scaling.
    delay(200);
    line(x0,y0,x2,y2);
    delay(200);
    line(x2,y2,x3,y3);
    delay(200);
    line(x1,y1,x3,y3+1);
    delay(200);
    getch();
    closegraph();
}
int main()
{
    string s;

    while(1)
    {

        printf("Enter option:\n\n");
        printf("1. DDA Line\n");
        printf("2. Bresenham Line\n");
        printf("3. Bresenham Circle\n");
        printf("4. Bangladesh flag\n");
        printf("5. Midpoint Ellipse\n");
        printf("6. Transition, rotation and scaling of a rectangle\n");
        printf("7. Cohen - Sutherlan line clipping\n");
        printf("8. utherland- Hodgman polygon clipping\n");
        printf("9. Exit\n");
        int x;
       scanf("%d",&x);
       if(x == 1)
       {
           dda();
       }
       else if(x == 2)
       {
           bresenham_line();
       }
       else if(x == 3)
       {
           bresenham_circle();
       }
       else if (x == 4)
       {
           national_flag();
       }
       else if(x == 5)
       {
           ellipse();
       }
       else if(x == 6)
       {
            transformxx();
       }
       else if(x == 7)
       {
           cohen_line_clip();
       }
       else if(x == 8)
       {
           sutherland_Hodgman_polygon_clipping();
       }
       else
       {
           printf("Thank You\n");
           break;
       }
    }
}
