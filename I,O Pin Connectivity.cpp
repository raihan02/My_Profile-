/*
#define int64_t long long int

typedef struct int_point
{
    long long int x,y,z;
    int_point()
    {
        x = 0;
        y = 0;
        z = 0;
    };
}point;

typedef struct double_point
{
    double x,y,z;
    double_point()
    {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    };
}dpoint;
*/
#include <bits/stdc++.h>
using namespace std;
#include "coordinate.h"
class BIN
{
public:
    BIN *parent;
    BIN **child;
    char* ID;
    int64_t no_of_child;
    point MIN, MAX;
    bool isLeaf()
    {
        return no_of_child==0;
    }
    BIN()
    {
        parent=NULL;
        child=NULL;
        ID = 0;
        no_of_child=0;
        MIN.x=0;
        MIN.y=0;
        MIN.z=0;
        MAX.x=0;
        MAX.y=0;
        MAX.z=0;
    }
};

class indv_level
{
public:
    int64_t no_of_nodes;
    BIN **node_array;
    int64_t min_len_x, min_len_y, min_len_z;
    indv_level()
    {
        no_of_nodes=0;
        node_array=NULL;
        min_len_x=0;
        min_len_y=0;
        min_len_z=0;
    };
};
class H_level_tree
{
public:
    int64_t no_of_level; //this is 0-based value, i.e for level 0,1,2 the no_of_level=2
    indv_level *l_array;
    H_level_tree()
    {
        no_of_level=0;
        l_array=NULL;
    };
};

typedef enum surf_e
{
    south = 0, //common Zmin
    north = 1, //common Zmax
    west  = 2, //common Xmin
    east  = 3, //common Xmax
    front = 4, //common Ymin
    back  = 5 //common Ymax
} surf_t;

class hl_id_t
{
public:
    long long int level_i;
    long long int node_j;
    surf_t surf_pos;
};

class point_c
{
public:
    point pin;
    surf_t surf_pos; //
//  point connected_to;
//  hl_id_t connected_id;
};

class nodal_pins
{
public:
//  hl_id_t hl_id;
    point MIN, MAX;
    point center_point;
    bool leaf_flag;
    vector<point_c*> io_pins;
};

class indv_level_nets
{
public:
    int no_of_nodes;
    nodal_pins *node_io_lists;
};

class hlnl
{
public:
    int no_of_levels; //this is 0-based value, i.e for level 0,1,2 the no_of_level=2
    indv_level_nets *netlists;
};

void set_pin_cordnt(BIN* node, nodal_pins *pic)
{

    if(node==NULL || pic==NULL || pic->leaf_flag==0)
    {
        std::cout<<"dbg_::set_pin_cordnt:: Null pointer/leaf error\n";
        exit(-1);
    }
    //cout<<node->ID << endl;
    // We assume that hl_id of the pin cluster for
    // this give node pic is already assigned by upper
    // level function
    int64_t x_min = node->MIN.x;
    int64_t y_min = node->MIN.y;
    int64_t z_min = node->MIN.z;
    pic->MIN.x = x_min;
    pic->MIN.y = y_min;
    pic->MIN.z = z_min;
    int64_t x_max = node->MAX.x;
    int64_t y_max = node->MAX.y;
    int64_t z_max = node->MAX.z;
    pic->MAX.x = x_max;
    pic->MAX.y = y_max;
    pic->MAX.z = z_max;
    int64_t x = (x_min+x_max)/2;
    int64_t y = (y_min+y_max)/2;
    int64_t z = (z_min+z_max)/2;
    pic->center_point.x = x;
    pic->center_point.y = y;
    pic->center_point.z = z;
    if(pic->io_pins.size()!=0)
    {
        cout<<"Error:3D_io_pin: illegal reassignment\n";
        exit(-1);
    }
    for(int i = 0; i<6; i++)
    {
        point_c *pin_ptr = new point_c[1];
        pin_ptr->pin.x = x;
        pin_ptr->pin.y = y;
        pin_ptr->pin.z = z;
        if(i==0) //South Surface center point
        {
            pin_ptr->surf_pos = south;
            pin_ptr->pin.z = z_min;
        }
        else if(i==1) //North Surface center point
        {
            pin_ptr->surf_pos = north;
            pin_ptr->pin.z = z_max;
        }
        else if(i==2) //West Surface center point
        {
            pin_ptr->surf_pos = west;
            pin_ptr->pin.x = x_min;
        }
        else if(i==3) //East Surface center point
        {
            pin_ptr->surf_pos = east;
            pin_ptr->pin.x = x_max;
        }
        else if(i==4) //Front Surface center point
        {
            pin_ptr->surf_pos = front;
            pin_ptr->pin.y = (unsigned)y_min;
        }
        else         //Back Surface center point
        {
            pin_ptr->surf_pos = back;
            pin_ptr->pin.y = (unsigned)y_max;
        }
        pic->io_pins.push_back(pin_ptr);

    }
    cout<< "Position for node" <<" " << node->ID <<  endl;
    for(int i = 0; i < pic->io_pins.size(); i++)
    {
        cout<<"Pin Coordinate " << pic->io_pins[i]->pin.x <<" " << pic->io_pins[i]->pin.y <<" " << pic->io_pins[i]->pin.y <<  endl;
    }
    pic->io_pins.clear();
}
void print_nodes (H_level_tree* hltree)
{

    for(int i=0; i<hltree->no_of_level; i++) // 3 is highest level .
    {
        for(int j=0; j<hltree->l_array[i].no_of_nodes; j++)
        {
            BIN* res;
            res= hltree->l_array[i].node_array[j];
            cout<<"L[" <<i + 1<<"].node["<< j <<"] contains Id = "<<res->ID<<endl;
            if(res->isLeaf())
            {
                cout<< res->ID << " is leaf" << endl;
            }
            else
            {
               cout<<res->ID << " contains ";
               for(int k = 0; k < res->no_of_child; k++)
               {
                    cout<< res->child[k]->ID << " ";
               }
               cout<< endl;
            }
        }
        cout<<endl;
    }

}
int main()
{
    nodal_pins *pic = new nodal_pins[1];
    BIN *Root = new BIN[1];
    H_level_tree *hltree = new H_level_tree[1];
    map<int, string> mp;
    Root->MIN.x = 0;
    Root->MIN.y = 0;
    Root->MIN.z = 0;
    Root->MAX.x = 40;
    Root->MAX.y = 40;
    Root->MAX.z = 0;
    Root->ID = "Root";
    Root->no_of_child=4;


    BIN *A = new BIN[1];
    A->MIN.x = 0;
    A->MIN.y = 20;
    A->MIN.z = 0;
    A->MAX.x = 15;
    A->MAX.y = 40;
    A->MAX.z = 0;
    A->ID = "A";
    A->no_of_child=0;
    BIN *B = new BIN[1];
    B->MIN.x = 15;
    B->MIN.y = 20;
    B->MIN.z = 0;
    B->MAX.x = 40;
    B->MAX.y = 40;
    B->MAX.z =  0;
    B->ID = "B";
    B->no_of_child=0;
    BIN *C = new BIN[1];
    C->MIN.x = 0;
    C->MIN.y = 0;
    C->MIN.z = 0;
    C->MAX.x = 15 ;
    C->MAX.y = 20;
    C->MAX.z = 0;
    C->ID = "C";
    C->no_of_child=0;
    BIN *D = new BIN[1];
    D->MIN.x = 15;
    D->MIN.y = 0;
    D->MIN.z = 0;
    D->MAX.x = 40;
    D->MAX.y = 20;
    D->MAX.z = 0;
    D->ID = "D";
    D->no_of_child=3;


    BIN *N = new BIN[1];
    N->MIN.x = 15;
    N->MIN.y = 0;
    N->MIN.z = 0;
    N->MAX.x = 23;
    N->MAX.y = 20;
    N->MAX.z = 0;
    N->ID = "N";
    N->no_of_child=3;
    BIN *O = new BIN[1];
    O->MIN.x = 23;
    O->MIN.y = 0;
    O->MIN.z = 0;
    O->MAX.x = 31;
    O->MAX.y = 20;
    O->MAX.z = 0;
    O->ID = "O";
    O->no_of_child=3;

    BIN *P = new BIN[1];
    P->MIN.x = 31;
    P->MIN.y = 0;
    P->MIN.z = 0;
    P->MAX.x = 40;
    P->MAX.y = 20;
    P->MAX.z = 0;
    P->ID = "P";
    P->no_of_child=3;

    BIN *E = new BIN[1];
    E->MIN.x = 15;
    E->MIN.y = 13;
    E->MIN.z = 0;
    E->MAX.x = 23;
    E->MAX.y = 20;
    E->MAX.z = 0;
    E->ID = "E";
    E->no_of_child=0;

    BIN *H = new BIN[1];
    H->MIN.x = 15;
    H->MIN.y = 6;
    H->MIN.z = 0;
    H->MAX.x = 23;
    H->MAX.y = 13;
    H->MAX.z = 0;
    H->ID = "H";
    H->no_of_child=0;

    BIN *K = new BIN[1];
    K->MIN.x = 15;
    K->MIN.y = 0;
    K->MIN.z = 0;
    K->MAX.x = 23;
    K->MAX.y = 6;
    K->MAX.z = 0;
    K->ID = "K";
    K->no_of_child=0;

    BIN *F = new BIN[1];
    F->MIN.x = 23;
    F->MIN.y = 13;
    F->MIN.z = 0;
    F->MAX.x = 31;
    F->MAX.y = 20;
    F->MAX.z = 0;
    F->ID = "F";
    F->no_of_child=0;

    BIN *I = new BIN[1];
    I->MIN.x = 23;
    I->MIN.y = 7;
    I->MIN.z = 0;
    I->MAX.x = 31;
    I->MAX.y = 13;
    I->MAX.z = 0;
    I->ID ="I";
    I->no_of_child=0;

    BIN *L = new BIN[1];
    L->MIN.x = 23;
    L->MIN.y = 0;
    L->MIN.z = 0;
    L->MAX.x = 31;
    L->MAX.y = 6;
    L->MAX.z = 0;
    L->ID = "L";
    L->no_of_child=0;

    BIN *G = new BIN[1];
    G->MIN.x = 31;
    G->MIN.y = 13;
    G->MIN.z = 0;
    G->MAX.x = 40;
    G->MAX.y = 20;
    G->MAX.z = 0;
    G->ID = "G";
    G->no_of_child=0;

    BIN *J = new BIN[1];
    J->MIN.x = 31;
    J->MIN.y = 7;
    J->MIN.z = 0;
    J->MAX.x = 30;
    J->MAX.y = 13;
    J->MAX.z = 0;
    J->ID = "J";
    J->no_of_child=0;

    BIN *M = new BIN[1];
    M->MIN.x = 31;
    M->MIN.y = 0;
    M->MIN.z = 0;
    M->MAX.x = 10;
    M->MAX.y = 6;
    M->MAX.z = 0;
    M->ID = "M";
    M->no_of_child=0;


// Build the tree first:: hints- parent child
    Root->child = (BIN**) malloc(sizeof(BIN*)*4);
    Root->child[0] = A;
    Root->child[1] = B;
    Root->child[2] = C;
    Root->child[3] = D;
    D->child = (BIN**) malloc(sizeof(BIN*)*3);
    D->child[0] = N;
    D->child[1] = O;
    D->child[2] = P;
    N->child = (BIN**) malloc(sizeof(BIN*)*3);
    N->child[0] = E;
    N->child[1] = H;
    N->child[2] = K;
    O->child = (BIN**) malloc(sizeof(BIN*)*3);
    O->child[0] = F;
    O->child[1] = I;
    O->child[2] = L;
    P->child = (BIN**) malloc(sizeof(BIN*)*3);
    P->child[0] = G;
    P->child[1] = J;
    P->child[2] = M;

    hltree->no_of_level = 3;
    hltree->l_array = new indv_level[hltree->no_of_level+1];

    hltree->l_array[0].no_of_nodes=4;
    hltree->l_array[0].node_array = (BIN**) malloc(sizeof(BIN*)*4);
    hltree->l_array[0].node_array[0] = A;
    hltree->l_array[0].node_array[1] = B;
    hltree->l_array[0].node_array[2] = C;
    hltree->l_array[0].node_array[3] = D;


    hltree->l_array[1].no_of_nodes=3;
    hltree->l_array[1].node_array = (BIN**) malloc(sizeof(BIN*)*3);
    hltree->l_array[1].node_array[0] = N;
    hltree->l_array[1].node_array[1] = O;
    hltree->l_array[1].node_array[2] = P;

    hltree->l_array[2].no_of_nodes=9;
    hltree->l_array[2].node_array = (BIN**) malloc(sizeof(BIN*)*9);
    hltree->l_array[2].node_array[0] = E;
    hltree->l_array[2].node_array[1] = H;
    hltree->l_array[2].node_array[2] = K;
    hltree->l_array[2].node_array[3] = F;
    hltree->l_array[2].node_array[4] = I;
    hltree->l_array[2].node_array[5] = L;
    hltree->l_array[2].node_array[6] = G;
    hltree->l_array[2].node_array[7] = J;
    hltree->l_array[2].node_array[8] = M;
    print_nodes(hltree);
}

