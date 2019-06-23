#ifndef SHORTEST_H
#define SHORTEST_H
#include <QString>
typedef struct Arccell
{
    int path;
} AdiMatrix[25][25];
typedef struct
{
    QString city[25];
    AdiMatrix arcs;
    int vexnum, arcnum;
}MGraph;

class shortestpath
{
public:
    shortestpath();
    MGraph G;
    bool P[25][25];
    bool P1[25][25][25];
    void StortPath(MGraph G, QString s, QString *p,bool P[25][25], int *D);
    void StortPath1(MGraph G,bool p[][25][25], int d[][25]);
    QString starcity;
    QString overcity;
};

#endif // SHORTEST_H
