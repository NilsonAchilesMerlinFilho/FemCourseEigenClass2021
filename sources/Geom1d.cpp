/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Geom1d.h"

Geom1d::Geom1d() {
}

Geom1d::~Geom1d() {
}

Geom1d::Geom1d(const Geom1d &copy) {
    fNodeIndices = copy.fNodeIndices;
}

Geom1d& Geom1d::operator=(const Geom1d& copy) {
    fNodeIndices = copy.fNodeIndices;
    return *this;
}

void Geom1d::Shape(const VecDouble &xi, VecDouble &phi, MatrixDouble &dphi) {
   
    if (phi.size() != 2) DebugStop();
   
    phi[0] = (1 - xi[0]) / 2.;
    phi[1] = (1 + xi[0]) / 2.;

    dphi(0,0) = -0.5;
    dphi(0,1) = 0.5;

}

void Geom1d::X(const VecDouble &xi, MatrixDouble &NodeCo, VecDouble &x) {
    if(xi.size() != Dimension) DebugStop();
    if(x.size() < NodeCo.rows()) DebugStop();
    if(NodeCo.cols() != nCorners) DebugStop();
    VecDouble phi(nCorners);
    MatrixDouble dphi(Dimension,nCorners);

    Shape(xi,phi,dphi);

    int nrow = NodeCo.rows();
    int ncol = NodeCo.cols();
    x.setZero();
    for (int i = 0; i < nCorners; i++) {
        for (int j = 0; j < nrow; j++) {
            x[j] += NodeCo(j,i) * phi[i];
        }
    }

}

void Geom1d::GradX(const VecDouble &xi, MatrixDouble &NodeCo, VecDouble &x, MatrixDouble &gradx) {
    if(xi.size() != Dimension) DebugStop();
    if(x.size() != NodeCo.rows()) DebugStop();
    if(NodeCo.cols() != nCorners) DebugStop();
    VecDouble phi(nCorners);
    MatrixDouble dphi(Dimension,nCorners);

    Shape(xi,phi,dphi);

    int ndirections = NodeCo.rows();
    int npoints = NodeCo.cols();
    x.setZero();
    gradx.resize(ndirections,1);
    gradx.fill(0);
    for (int i = 0; i < ndirections; i++) {
        for (int j = 0; j < npoints; j++) {
            x[i] += NodeCo(i,j)*phi[j];
            gradx(i,0) += NodeCo(i,j)*dphi(0,j);
        }
    }
}

void Geom1d::SetNodes(const VecInt &nodes) {
    if(nodes.rows() != 2) DebugStop();
    fNodeIndices = nodes;
}

void Geom1d::GetNodes(VecInt &nodes) const {
    nodes = fNodeIndices;
}

int Geom1d::NodeIndex(int node) const {
    if(node<0 || node > 2) DebugStop();
    return fNodeIndices[node];
}

int Geom1d::NumNodes(){
    return nCorners;    
}

GeoElementSide Geom1d::Neighbour(int side) const{
    if(side <0 || side>2) DebugStop();
    return fNeighbours[side];
}

void Geom1d::SetNeighbour(int side, const GeoElementSide &neighbour) {
    if(side < 0 || side > 2) DebugStop();
    fNeighbours[side]=neighbour;
}
