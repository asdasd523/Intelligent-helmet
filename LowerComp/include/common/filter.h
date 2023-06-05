#ifndef _FILTER_H
#define _FILTER_H

class Kalman_filter{
public:
    Kalman_filter(){
        PP[0][0] = 1;
        PP[1][1] = 1;
    }

    void set_value(short acc,short gyo){
        Accel = acc;
        Gyro = gyo;
    }

    float get_value()
    {
        return angle;
    }

    void filter();


private:
    float K1 = 0.02;
    float Q_angle=0.001;// 过程噪声的协方差
    float Q_gyro=0.003  ;//0.003 过程噪声的协方差 过程噪声的协方差为一个一行两列矩阵
    float R_angle=0.5;// 测量噪声的协方差 既测量偏差
    float dt=0.005;                
    char  C_0 = 1;

    float Q_bias;
    float Angle_err;
    float PCt_0;
    float PCt_1;
    float E;
    float K_0;
    float K_1;
    float t_0;
    float t_1;
    float angle;
    float angle_dot;
    float Accel;
    float Gyro;
    float Pdot[4];
    float PP[2][2];
};





#endif