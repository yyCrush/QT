#include "shortestpath.h"

shortestpath::shortestpath()
{
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            P[i][j]=false;
            for(int m=0;m<25;m++)
            {
                P1[i][j][m]=false;
            }
        }
    }
   starcity="";
   overcity="";
   G.city[0]= "成都";
   G.city[1]="昆明";
   G.city[2]="贵阳";
   G.city[3]="柳州";
   G.city[4]="南宁";
   G.city[5]="株州";
   G.city[6]="广州";
   G.city[7]="深圳";
   G.city[8]="南昌";
   G.city[9]="福州";
   G.city[10]="上海";
   G.city[11]="武汉";
   G.city[12]="徐州";
   G.city[13]="郑州";
   G.city[14]="天津";
   G.city[15]="北京";
   G.city[16]="沈阳";
   G.city[17]="大连";
   G.city[18]="长春";
   G.city[19]="哈尔";
   G.city[20]="西安";
   G.city[21]="呼和浩特";
   G.city[22]="兰州";
   G.city[23]="西宁";
   G.city[24]="乌鲁木齐";
   G.arcnum = 20;
    G.vexnum = 25;
    for (int i = 0; i<25; i++)
    {
        for (int j = 0; j<25; j++)
        {
            if (i == 0 && j == 1||(i==1&&j==0))
            {
                G.arcs[0][1].path = 1100;
                G.arcs[1][0].path = 1100;
            }
            else if (i == 0 && j== 2 || (i == 2 && j == 0))
            {
                G.arcs[i][j].path = 967;
                G.arcs[j][i].path = 967;
            }
            else if (i == 0 && j == 20 || (i == 20 && j == 0))
            {
                G.arcs[i][j].path = 842;
                G.arcs[i][j].path = 842;
            }
            else if (i == 1 && j == 2 || (i == 2 && j == 1))
            {
                G.arcs[i][j].path = 639;
                G.arcs[j][i].path = 639;
            }
            else if (i == 2 && j == 5 || (i == 5 && j == 2))
            {
                G.arcs[i][j].path = 902;
                G.arcs[j][i].path = 902;
            }
            else if (i == 2 && j == 3 || (i == 3 && j == 2))
            {
                G.arcs[i][j].path = 607;
                G.arcs[j][i].path = 607;
            }
            else if (i == 3 && j == 4 || (i == 4 && j == 3))
            {
                G.arcs[i][j].path = 255;
                G.arcs[j][i].path = 255;
            }
            else if (i == 3 && j == 5 || (i == 5 && j == 3))
            {
                G.arcs[i][j].path = 672;
                G.arcs[j][i].path = 672;
            }

            else if (i == 6 && j == 5 || (i == 5 && j == 6))
            {
                G.arcs[i][j].path = 675;
                G.arcs[j][i].path = 675;
            }
            else if (i == 7 && j == 6 || (i == 6 && j == 7))
            {
                G.arcs[i][j].path = 140;
                G.arcs[j][i].path = 140;
            }
            else if (i == 5 && j == 8|| (i == 8 && j == 5))
            {
                G.arcs[i][j].path = 367;
                G.arcs[j][i].path = 367;
            }
            else if (i == 5 && j == 11 || (i == 11 && j == 5))
            {
                G.arcs[i][j].path = 409;
                G.arcs[j][i].path = 409;
            }
            else if (i == 9 && j == 8 || (i == 8 && j == 9))
            {
                G.arcs[i][j].path = 622;
                G.arcs[j][i].path = 622;
            }
            else if (i == 8 && j == 10 || (i == 10 && j == 8))
            {
                G.arcs[i][j].path = 825;
                G.arcs[j][i].path = 825;
            }
            else if (i == 10 && j == 12 || (i == 12 && j == 10))
            {
                G.arcs[i][j].path = 651;
                G.arcs[j][i].path = 651;
            }
            else if (i == 13 && j == 12 || (i == 12 && j == 13))
            {
                G.arcs[i][j].path = 349;
                G.arcs[j][i].path = 349;
            }
            else if (i == 11 && j == 13 || (i == 13 && j == 11))
            {
                G.arcs[i][j].path = 534;
                G.arcs[j][i].path = 534;
            }
            else if (i == 13 && j == 20 || (i == 20&& j == 13))
            {
                G.arcs[i][j].path = 511;
                G.arcs[j][i].path = 511;
            }
            else if (i == 13 && j == 15 || (i == 15 && j == 13))
            {
                G.arcs[i][j].path = 695;
                G.arcs[j][i].path = 695;
            }
            else if (i == 12 && j == 14 || (i == 14 && j == 12))
            {
                G.arcs[i][j].path = 674;
                G.arcs[j][i].path = 674;
            }
            else if (i == 16 && j == 14 || (i == 14 && j == 16))
            {
                G.arcs[i][j].path = 704;
                G.arcs[j][i].path = 704;
            }
            else if (i == 16 && j == 17 || (i == 17 && j == 16))
            {
                G.arcs[i][j].path = 397;
                G.arcs[j][i].path = 397;
            }
            else if (i == 16 && j == 18|| (i == 18 && j == 16))
            {
                G.arcs[i][j].path = 305;
                G.arcs[j][i].path = 305;
            }
            else if (i == 18 && j == 19 || (i == 19&& j == 18))
            {
                G.arcs[i][j].path = 242;
                G.arcs[j][i].path = 242;
            }
            else if (i == 20 && j == 22 || (i == 22 && j == 20))
            {
                G.arcs[i][j].path = 676;
                G.arcs[j][i].path = 676;
            }
            else if (i == 22 && j == 23 || (i == 23 && j == 22))
            {
                G.arcs[i][j].path = 216;
                G.arcs[j][i].path = 216;
            }
            else if (i == 22 && j == 24 || (i == 24 && j == 22))
            {
                G.arcs[i][j].path = 1892;
                G.arcs[j][i].path = 1892;
            }
            else if (i == 15 && j == 14 || (i == 14 && j == 15))
            {
                G.arcs[i][j].path = 137;
                G.arcs[j][i].path = 137;
            }
            else if (i == 15 && j == 21 || (i == 21 && j == 15))
            {
                G.arcs[i][j].path = 668;
                G.arcs[j][i].path = 668;
            }
            else if (i == 22 && j == 21 || (i == 21 && j == 22))
            {
                G.arcs[i][j].path = 1145;
                G.arcs[j][i].path = 1145;
            }
            else
                G.arcs[i][j].path = 999999;
        }
    }
}
void shortestpath::StortPath(MGraph G, QString s, QString *p,bool P[25][25], int *D)
{
    int v;
    for (int j = 0; j < 25; j++)
    {
        if (s == p[j])
            v = j;
    }
    bool final[25];
    for (int m = 0; m<G.vexnum; ++m)
    {
        final[m] = false;
        D[m] = G.arcs[v][m].path;
        for (int w = 0; w<G.vexnum; ++w) { P[m][w] = false; }
        if (D[m] < 999999) { P[m][v] = true; P[m][m] = true; }
    }
    D[v] = 0; final[v] = true;
    int c;
    for (int i = 1; i<G.vexnum; ++i)
    {
        int min = 999999;
        for (int m = 0; m<G.vexnum; ++m)
        {
            if (!final[m])
            {
                if (D[m]<min) { c = m; min = D[m]; }
            }
        }
        final[c] = true;
        for (int m = 0; m < G.vexnum; m++)
        {
            if (!final[m] && ((min + G.arcs[c][m].path) < D[m]))
            {
                D[m] = min + G.arcs[c][m].path;
                for (int i = 0; i < G.vexnum; i++)
                {
                  P[m][i] = P[c][i];
                }
                P[m][m] = true;
            }
        }
    }
}
void shortestpath::StortPath1(MGraph G,bool p[][25][25], int d[][25])
{
    for (int v = 0; v < G.vexnum; v++)
    {
        for (int w = 0; w < G.vexnum; w++)
        {
            d[v][w] = G.arcs[v][w].path;
            for (int u = 0; u < G.vexnum; u++)  p[v][w][u] = false;
            if (d[v][w] < 999999)
            {
                p[v][w][v] = true;  p[v][w][w] = true;
            }
        }
    }
    for (int u = 0; u < G.vexnum; u++)
    {
        for (int v = 0; v < G.vexnum; v++)
        {
            for (int w = 0; w < G.vexnum; w++)
            {
                if (d[v][u] + d[u][w] < d[v][w])
                {
                    d[v][w] = d[v][u] + d[u][w];
                    for (int i = 0; i < G.vexnum; i++)
                    {
                        p[v][w][i] = p[v][u][i] || p[u][w][i];
                    }
                }
            }
        }
    }
}
