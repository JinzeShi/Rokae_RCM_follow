#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define M 50
#define my_eps 0.00001
#define inf 0x3f3f3f3f
#define mod 1070000009
#define PI 3.141592653
using namespace std;

// ��
struct node
{
    double x, y, z;      //node��Ԫ��
    node() {}
    node(double xx, double yy, double zz) :x(xx), y(yy), z(zz) {}

    //���������
    node operator +(const node p)	//��������Ӳ���
    {
        return node(x + p.x, y + p.y, z + p.z);
    }
    node operator -(const node p)	//�������������
    {
        return node(x - p.x, y - p.y, z - p.z);
    }
    node operator *(const node p)	//�������˲���
    {
        return node(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
    }
    node operator *(const double p)	//��������һ����
    {
        return node(x * p, y * p, z * p);
    }
    node operator /(const double p)	//��������һ����
    {
        return node(x / p, y / p, z / p);
    }
    double operator ^(const node p)	//�������˲���
    {
        return x * p.x + y * p.y + z * p.z;
    }
};


// ����������
struct face
{
    int a, b, c;  // ͹��һ�����ϵ�������ı��
    int ok;       // �����Ƿ�������͹���е���
    
    face() {}
};


// �����ʾ��ά͹������
// �����ж��������õ���һЩ�����ͺ���
class Convex_hull
{   
public:

    Convex_hull() {
        cnt = 0;
        Input_node_num = 0;
        Convex_node_num = 0;
        Convex_face_num = 0;
        cout << "Convex_hull" << endl;
    }

    ~Convex_hull() {}

    
    void Sum_node_number(int num) { Input_node_num = num; }   // ����Input_node_num��Ŀ
  
    void Input_node(int index, node point) {  p[index] = point; }         // �����

    double len(node p)      // �����ĳ��ȡ�ģ
    {
        return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
    }

    double area(node a, node b, node c)       // ����������*2
    {
        return len((b - a) * (c - a));
    }

    double volume(node a, node b, node c, node d)  // ���������*6
    {
        return (b - a) * (c - a) ^ (d - a);
    }


    // ����ptof������ͨ����������������жϵ�����ķ���
    // ��Ϊ����������ͬ��
    double ptof(node q, face f);

    // ����deal��dfs��������������͹��
    void deal(int q, int a, int b);

    // ά��͹��������q��͹���������͹��
    void dfs(int q, int cur);

    // �ж������������Ƿ��棬���������ι����򷵻�1
    int same(int s, int t);

    // ����3D͹��
    void make();

    // �ж�һ�����Ƿ���͹���ڲ������ڲ�����1�����ⲿ����0
    int judge(node p);

    // ����һ���㵽͹����һ��ƽ��ľ���
    double dis_to_face(node q, face f);

    // ����һ���㵽͹���ϸ��������С����
    double min_dis_to_convex(node p);


private:
    node p[M];                 // ����ĳ�ʼ��
    face f[M * 8];             // ͹��������
    vector<int> v;             // �����ã�������
    int cnt;                   // ͹������������������������
    int to[M][M];              // ��i��j������͹���ڵ��ĸ���

public:
    int Input_node_num;          // ��ʼ����(p[M]���鵱�е�ĸ���)
    int Convex_node_num;         // ͹��������Ŀ
    int Convex_face_num;         // ͹��������Ŀ

    vector<node> Points_in_Convex;   // ���������汣��͹������Ķ���
    vector<face> Faces_in_Convex;    // ���������汣��͹������ı���
};



