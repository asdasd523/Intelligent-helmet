#include "common/filter.h"

void Kalman_filter::filter()
{
    angle+=(Gyro - Q_bias) * dt; //1.先验估计 计算角度  公式一

    Pdot[0]=Q_angle - PP[0][1] - PP[1][0]; // Pk-先验估计误差协方差的微分
    Pdot[1]=-PP[1][1];
    Pdot[2]=-PP[1][1];
    Pdot[3]=Q_gyro;

    PP[0][0] += Pdot[0] * dt;   //2 Pk-先验估计误差协方差微分的积分  公式二
    PP[0][1] += Pdot[1] * dt;   // =先验估计误差协方差
    PP[1][0] += Pdot[2] * dt;
    PP[1][1] += Pdot[3] * dt;

    Angle_err = Accel - angle; //zk-先验估计3 角度的残差

    PCt_0 = C_0 * PP[0][0];  
    PCt_1 = C_0 * PP[1][0];

    E = R_angle + C_0 * PCt_0;   // 4 

    K_0 = PCt_0 / E;
    K_1 = PCt_1 / E;   // 5  公式三  卡尔曼增益

    t_0 = PCt_0;
    t_1 = C_0 * PP[0][1];

    PP[0][0] -= K_0 * t_0;  //  7  后验估计误差协方差  公式五
    PP[0][1] -= K_0 * t_1;
    PP[1][0] -= K_1 * t_0;
    PP[1][1] -= K_1 * t_1;

    angle += K_0 * Angle_err;  //后验估计   //6  公式四当前的估计值=上一次的估计值+系数*（当前测量值-上一次的估计值） 
    Q_bias += K_1 * Angle_err;  //后验估计 

    angle_dot   = Gyro - Q_bias;  //输出值(后验估计)的微分=角速度
}