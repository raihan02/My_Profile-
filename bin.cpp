#include <bits/stdc++.h>
using namespace std;
typedef struct uint_point{
     double x,y,z;
    //std::bitset<96> pin;
    unit_point()
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
    double no_of_sub_bl;
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
    double x, y, z;
    double r;
    Sphere()
    {
        x = 0, y = 0, z = 0;
    }
};
bool inside(block bk,double x,double y, double z)
{
    if(x >= bk.MIN.x && x <= bk.MAX.x && y >= bk.MIN.y && y <= bk.MAX.y && z >= bk.MIN.z && z <= bk.MAX.z)
    {
        return true;
    }
    return false;
}
bool check_inside (block bk, Sphere ss)
{
    double mx1,my1,mz1,mx2,my2, mz2,flag;

    mx1 = ss.r + ss.x;
    flag=inside(bk,mx1,ss.y,ss.z);
    if(flag==false)
        return false;
    mx2 = ss.x-ss.r;
    flag=inside(bk,mx2,ss.y,ss.z);
    if(flag==false)
        return false;
    my1 = ss.r + ss.y;
    flag=inside(bk,ss.x,my1,ss.z);
    if(flag==false)
        return false;
    my2 = ss.y - ss.r;
    flag=inside(bk,ss.x,my2,ss.z);
    if(flag==false)
        return false;
    mz1 = ss.r + ss.z;
    flag=inside(bk,ss.x,ss.y,mz1);
    if(flag==false)
        return false;
    mz2 = ss.z - ss.r;
    flag=inside(bk,ss.x,ss.y,mz2);
    if(flag==false)
        return false;

    return true;
}
bool check_equation (Sphere sp, double x, double y, double z)
{
    if((((sp.x - x) * (sp.x - x))+ ((sp.y - y) * (sp.y - y)) + ((sp.z - z) * (sp.z - z))) <= (sp.r * sp.r))
    {
        return true;
    }
    return  false;
}
double cnt= 0;
void valid_grid (block bk, Sphere sp, vector<block> &blocks)
{

    double center_x, center_y, center_z;
    center_x = (bk.MIN.x + bk.MAX.x)/2.0;
    center_y = (bk.MIN.y + bk.MAX.y)/2.0;
    center_z = (bk.MIN.z + bk.MAX.z)/2.0;
    bool check = check_equation(sp, center_x,center_y,center_z);
    if(check == true)
    {
        cnt++;
        //cout<< bk.MIN.x<< " "<<bk.MIN.y<< " " << bk.MIN.z<<endl;
        //cout<< bk.MAX.x<< " "<<bk.MAX.y<< " " << bk.MAX.z<<endl;
        blocks.push_back(bk);
    }
    ///cout<<blocks.size()<< endl;

}

void print_grid(vector<block> bk)
{
    for(int i = 0; i < bk.size(); i++)
    {
        cout<<"Min = " << bk[i].MIN.x<<" "<<bk[i].MIN.y<<" "<<bk[i].MIN.z<< endl;
        cout<<"Max = " << bk[i].MAX.x<<" "<<bk[i].MAX.y<<" "<<bk[i].MAX.z<< endl;
    }
}
void divide_block (block bk, double cut_x, double cut_y, double cut_z, Sphere sp,vector<block> &blocks)
{
    double x_min, y_min, z_min;
    double x_max, y_max, z_max;
    x_min = bk.MIN.x;
    y_min = bk.MIN.y;
    z_min = bk.MIN.z;
    x_max = bk.MAX.x;
    y_max = bk.MAX.y;
    z_max = bk.MAX.z;
    double dif_x, dif_y, dif_z;
    dif_x = x_max - x_min;
    dif_y = y_max - y_min;
    dif_z = z_max - z_min;
    if(cut_x==0 || cut_y==0 || cut_z==0)
    {
        cout<<"ERROR: cut lenght error "<<cut_x<<" "<<cut_y<<" "<<cut_z<<endl;
        return ;
    }
    double nx = dif_x / cut_x;
    double ny = dif_y / cut_y;
    double nz = dif_z / cut_z;
    double child = 0;
    cout<<"dbg_divide_grid: nx("<<nx<<") ny("<<ny<<") nz("<<nz<<")\n";
    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
                bk.MIN.x = (i * cut_x) + x_min;
                bk.MIN.y = (j * cut_y) + y_min;
                bk.MIN.z = (k * cut_z) + z_min;
                if(i==nx-1)
                {
                    bk.MAX.x = x_max;
                }
                else
                {
                    bk.MAX.x = ((i + 1) *cut_x) + x_min;
                }
                if(j==ny-1)
                {
                    bk.MAX.y = y_max;
                }
                else
                {
                    bk.MAX.y = ((j + 1) * cut_y) + y_min;
                }
                if(k == nz-1)
                {
                    bk.MAX.z = z_max;
                }
                else
                {
                    bk.MAX.z = ((k + 1) * cut_z) + z_min;
                }
                valid_grid(bk,sp,blocks);


            }
        }
    }

}


int main()
{
    Sphere sp;
    block blk;
    vector<block> blocks;

    sp.x = 0;
    sp.y = 0;
    sp.z = 0;
    sp.r = 3;
    double x1 = sp.x - sp.r - 1;
    double x2 = sp.x + sp.r + 1;
    blk.MIN.x = min(x1,x2);
    blk.MAX.x = max(x1, x2);

    double y1 = sp.y - sp.r - 1;
    double y2 = sp.y + sp.r + 1;
    blk.MIN.y = min(y1,y2);
    blk.MAX.y = max(y1, y2);
    double z1 = sp.z - sp.r - 1;
    double z2 = sp.z + sp.r + 1;
    blk.MIN.z = min(z1,z2);
    blk.MAX.z = max(z1, z2);
    cout<< blk.MIN.x<< " "<<blk.MIN.y<< " " << blk.MIN.z<<endl;
    cout<< blk.MAX.x<< " "<<blk.MAX.y<< " " << blk.MAX.z<<endl;

    bool check =  check_inside(blk, sp);
      cout<<check<< endl;
    if(check == true)
    {
        double cutx, cuty, cutz;
        //cin >> cutx>> cuty>> cutz;
        cout<<"Inside"<< endl;
        divide_block(blk,2, 2, 2,sp,blocks);
        print_grid(blocks);
        //cout<< blocks.size()<< endl;
    }

}
