int Z[100002];
void getZarr(st str)
{
    int n = str.length();
    int L, R, k;
    L = R = 0;
    f(i,1,n)
    {
        if (i > R){
            L = R = i;
            while (R<n && str[R-L] == str[R])R++;
            Z[i] = R-L;
            R--;
        }
        else{
            k = i-L;
            if (Z[k] < R-i+1)   Z[i] = Z[k];
            else{
                L = i;
                while (R<n && str[R-L] == str[R])R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

void search(st text, st pattern)
{
    st concat = pattern + "$" + text;
    int l = concat.length();
    getZarr(concat);

    f(i,0,l)    if (Z[i] == pattern.length())cout << "Pattern found at index "<<  i - pattern.length() -1 << endl;
}



int main(){
    //fin(prob);
    //fout(prob);
    c(st, text);c(st, pattern);
    search(text, pattern);
return 0;}
