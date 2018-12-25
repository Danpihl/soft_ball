#ifndef SOFT_BALL_H
#define SOFT_BALL_H

#include "sphere_subdivision/subdivisor.h"
#include "sphere_subdivision/point.h"

class SoftBall
{

  public:
    float m;
    float C;
    float K;
    float g;
    float h;

    float *P;
    float *V;
    float *A;
    float *Fv;
    float *Vp;
    float *Vpc;
    float F;
    float R;
    float room_limit;

    float *Ls; // Length between connections

    int N;

    // Center point:
    float *Pc; // Position
    float *Vc; // Velocity
    float *Ac; // Acceleration
    float Rc;  // Radii to other points

    int *number_of_connections;
    Subdivisor *subdivisor;

    float vc[3]; // Vectors to other points
    float Fc[3]; // Force to other points

    float Lc; // Length to center
    float Kc; // Spring constant
    float Cc; // Dampening constant center
    float mc; // Mass

    float Ca; // Air resistance

    float Ft;

    float vp[3];
    float v[3];
    float a[3];
    float ac[3];

    int *edgelist_idx1;
    int *edgelist_idx2;
    int N_edges;

    float *Rv;

    int idx_0, idx_1, idx_2, cidx;
    int lim;
    float r0;

    int i, k;

    float friction_threshold;
    float speed_threshold;
    float mu;
    float Nf;
    float v_speed;
    float v_0, v_2;

    void update();
    void set_velocity(float dir[3], float amp);
    void calculateRaiis();
    SoftBall(float m_, float C_, float K_,
             float h_, float Kc_, float Cc_,
             float mc_, float Lc_, float Ca_,
             float x0, float y0, float z0,
             int num_subdivisions);
    SoftBall();
    ~SoftBall();
};

#endif