#include <bits/stdc++.h>
using namespace std;
typedef struct uint_point
{
    unsigned int x,y,z;
    //std::bitset<96> pin;
    uint_point()
    {
        x = 0;
        y = 0;
        z = 0;
    };
} point;
class block
{
public:
    int ID;
    int no_of_sub_bl;
    point MIN, MAX;

    block()
    {
        ID = 0;
        no_of_sub_bl = 0;
        MIN.x=0;
        MIN.y=0;
        MIN.z=0;
        MAX.x=0;
        MAX.y=0;
        MAX.z=0;
    }
};

class Sphere
{
public:
    int x, y, z;
    int r;
    Sphere()
    {
        x = 0, y = 0, z = 0;
    }
};
bool check_inside (block bk, Sphere ss)
{
    int mx,my,mz;
    mx = ss.r+ ss.x;
    my = ss.r+ss.y;
    mz = ss.r + ss.z;
    if(mx >= bk.MIN.x && mx <= bk.MAX.x && my >= bk.MIN.y && my <= bk.MAX.y && mz >= bk.MIN.z && mz <= bk.MAX.z)
    {
        return true;
    }
    return false;
}

void valid_grid (block bk, Sphere ss)
{
    int center_x , center_y , center_z;
    center_x= bk.
}

void divide_block (block bk, int cut_x, int cut_y, int cut_z)
{
    int x_min, y_min, z_min;
    int x_max, y_max, z_max;
    x_min = bk.MIN.x;
    y_min = bk.MIN.y;
    z_min = bk.MIN.z;
    x_max = bk.MAX.x;
    y_max = bk.MAX.y;
    z_max = bk.MAX.z;
    int dif_x, dif_y, dif_z;
    dif_x = x_max - x_min;
    dif_y = y_max - y_min;
    dif_z = z_max - z_min;
    if(cut_x==0 || cut_y==0 || cut_z==0)
    {
        cout<<"ERROR: cut lenght error "<<cut_x<<" "<<cut_y<<" "<<cut_z<<endl;
        return ;
    }
    int nx = dif_x/cut_x; //number of pints in X-direction
    int ny = dif_y/cut_y; //number of pints in Y-direction
    int nz = dif_z/cut_z; //number of pints in Z-direction
    int child = 0;
    cout<<"dbg_divide_grid: nx("<<nx<<") ny("<<ny<<") nz("<<nz<<")\n";
    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
                bk.MIN.x = (i*cut_x) + x_min;
                bk.MIN.y = (j*cut_y) + y_min;
                bk.MIN.z = (k*cut_z) + z_min;
                if(i==nx-1) // remaining x>=cut_len_x but x<2*cut_len_x
                {
                    bk.MAX.x = x_max;
                }
                else
                {
                    bk.MAX.x = ((i+1)*cut_x) + x_min;
                }
                if(j==ny-1) // remaining y>=cut_len_y but y<2*cut_len_y
                {
                    bk.MAX.y = y_max;
                }
                else
                {
                    bk.MAX.y = ((j+1)*cut_y) + y_min;
                }
                if(k==nz-1) // remaining z>=cut_len_z but z<2*cut_len_z
                {
                    bk.MAX.z = z_max;
                }
                else
                {
                    bk.MAX.z = ((k+1)*cut_z) + z_min;
                }

                //cout<< bk.MIN.x << " " << bk.MIN.y << " " << bk.MIN.z << endl;
                //cout<< bk.MAX.x << " " << bk.MAX.y << " " << bk.MAX.z << endl;
            }
        }
    }

    //cout<< bk.blocks.size()<< endl;
}


int main()
{
    Sphere sp;
    block blk;
    cout<<"Enter Block Min MAX"<< endl;
    cin >>blk.MIN.x>>blk.MIN.y>>blk.MIN.z;
    cin >>blk.MAX.x>>blk.MAX.y>>blk.MAX.z;
    cout<<"Enter Sphere Center"<< endl;
    cin >>sp.x>>sp.y>>sp.z;
    cout<<"Enter Sphere Radius"<< endl;
    cin >> sp.r;
    check_inside(blk, sp);
    int cutx, cuty, cutz;
    cin >> cutx>> cuty>> cutz;

    divide_block(blk,cutx, cuty, cutz);


}
