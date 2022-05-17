#include <iostream>
#include "GeoMesh.h"
#include "GeoElementTemplate.h"
#include "Geom1d.h"
#include "VTKGeoMesh.h"
#include "CompMesh.h"
#include "Poisson.h"
#include "Analysis.h"
#include "PostProcessTemplate.h"
using namespace std;

int main(){

// Creating a Geometric mesh
int nNodes = 10;
int nElements = nNodes-1; 

GeoMesh *gmesh = new GeoMesh();
gmesh->SetDimension(1);
gmesh->SetNumNodes(nNodes);
gmesh->SetNumElements(nElements);

VecDouble coord(3);
coord[0] = 0.0;
coord[1] = 0.0;
coord[2] = 0.0;
gmesh->Node(0).SetCo(coord);

int matid = 1; // Material ID

double deltaX = 0.1;
double deltaY = 0.0;

for (int iEl = 0; iEl < nElements; iEl++) // Equivalente a iEl=iEl+1
{
    coord[0] = deltaX*(iEl+1);
    coord[1] = deltaY*(iEl+1);
    gmesh->Node(iEl+1).SetCo(coord);
    
    VecInt nodes(2);
    nodes[0] = iEl;
    nodes[1] = iEl + 1;
    GeoElement *gel = new GeoElementTemplate<Geom1d> (nodes, matid, gmesh, iEl);
    gmesh->SetElement(iEl,gel);
}

gmesh->BuildConnectivity();

gmesh->Print(std::cout);

VTKGeoMesh printer;
printer.PrintGMeshVTK(gmesh,"geoMesh.vtk");

// Cria uma malha computacional
CompMesh cmesh(gmesh);

// Estabelece um tipo de material
MatrixDouble perm(1,1);
perm(0,0)=1.;
Poisson *mat = new Poisson(matid,perm);

// Insere o material na malha computacional e cria o espaço de aproximação
cmesh.SetMathStatement(matid,mat);
cmesh.AutoBuild();

// Análise
Analysis an(&cmesh);
an.RunSimulation();

    return 0;
}