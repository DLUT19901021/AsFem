//****************************************************************
//* This file is part of the AsFem framework
//* A Simple Finite Element Method program (AsFem)
//* All rights reserved, Yang Bai @ CopyRight 2020
//* https://github.com/yangbai90/AsFem.git
//* Licensed under GNU GPLv3, please see LICENSE for details
//* https://www.gnu.org/licenses/gpl-3.0.en.html
//****************************************************************
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ Author : Yang Bai
//+++ Date   : 2020.06.30
//+++ Purpose: Implement the input file reader for AsFem
//+++          So, in this class, the input file for AsFem is only
//+++          accessible via this class
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


#include "petsc.h"

//**************************************
//*** For AsFem's own header file
//**************************************
#include "Utils/StringUtils.h"
#include "Utils/MessagePrinter.h"

#include "Mesh/Mesh.h"
#include "Mesh/MeshIO.h"
#include "DofHandler/DofHandler.h"
#include "ElmtSystem/ElmtSystem.h"
#include "MateSystem/MateSystem.h"


class InputSystem{
public:
    InputSystem(int args,char *argv[]);
    InputSystem();
    void InitInputSystem(int args,char *argv[]);

    bool ReadInputFile(Mesh &mesh,DofHandler &dofHandler,ElmtSystem &elmtSystem,MateSystem &mateSystem);

private:
    //******************************************************
    //*** functions for reading each block
    //******************************************************
    bool ReadMeshBlock(ifstream &in,string str,int &linenum,Mesh &mesh);
    bool ReadDofsBlock(ifstream &in,string str,int &linenum,DofHandler &dofHandler);
    bool ReadElmtBlock(ifstream &in,string str,const int &lastendlinenum,int &linenum,ElmtSystem &elmtSystem,DofHandler &dofHandler);
    bool ReadMateBlock(ifstream &in,string str,const int &lastendlinenum,int &linenum,MateSystem &mateSystem);

    //******************************************************
    //*** private variables
    //******************************************************
    MeshIO _meshio;
    string _InputFileName,_MeshFileName;
    bool _HasInputFileName=false;
    bool _IsBuiltInMesh=true;
    bool _IsReadOnly=false;

};