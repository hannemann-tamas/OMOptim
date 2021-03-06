// $Id$
/**
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL).
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE
 * OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3, ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * Main contributor 2010, Hubert Thierot, CEP - ARMINES (France)
 * Main contributor 2010, Hubert Thierot, CEP - ARMINES (France)

  @file ModPlusCtrl.cpp
  @brief Comments for file documentation.
  @author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
  Company : CEP - ARMINES (France)
  http://www-cep.ensmp.fr/english/
  @version

  */
#include "ModPlusCtrl.h"

#include "MOParameter.h"

#include "ModelPlus.h"

#include "Project.h"

ModPlusCtrl::ModPlusCtrl(Project* project,ModelPlus* ModPlus,MOomc* moomc)
{
    _project = project;
    _ModelPlus = ModPlus;
    _moomc = moomc;


    // _parameters are not created here; it will be in inheriting classes
    _parameters = NULL;
}

ModPlusCtrl::~ModPlusCtrl(void)
{
    if(_parameters)
        delete _parameters;
}

/** Uncompile model: remove compiled version.
  * Returns true if it has been successful or if there were no compiled version.
  * May be used when a model is reloaded, to force compiling it again.
  */
bool ModPlusCtrl::uncompile()
{
    return true;
}


MOParameters* ModPlusCtrl::parameters() const
{
    return _parameters;
}

bool operator==(const ModPlusCtrl &a, const ModPlusCtrl &b)
{
        bool sameType =  (a.type()==b.type());

        if(!sameType)
            return false;
        else
        {
            bool sameParameters = ((*a.parameters())==(*b.parameters()));
            return sameParameters;
        }
}





