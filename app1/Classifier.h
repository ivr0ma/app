#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <iostream>
#include <math.h>
#include <stdio.h>

class Classifier {
private:
    int work_tag[3][2];     // ������ ���������
    double func_coef[3][2]; // ������ ����-�� ��� ��������������� �������
public:
    int cl_A[15][10]; 
    int cl_B[15][10];
    int cl_C[15][10];
    int cl_D[15][10];
    int cl_AC[30][10];
    int cl_BD[30][10];

    Classifier(); // ����������� ������, ������������ ��������� �������������

    void read_file(char* file_path); // ��������� ������� ������� A,B,C,D �� �����
    double distance(int node_num, int* x, int* y); // ������� ���������� ����� ��������� ������
    int discr_func(int node_num, int* obj); // ���������� ��������������� �������
    int neighbour_1(int node_num, int* obj); // ���������� ������ 1-�� ���������� ������
    int neighbour_k(int k, int node_num, int* obj); // ���������� ������ k ��������� �������
    char recognize(int* obj); // ������������� �������
    bool voting(int node_num, int* obj); // ������� �����������
};

#endif //CLASSIFIER_H
