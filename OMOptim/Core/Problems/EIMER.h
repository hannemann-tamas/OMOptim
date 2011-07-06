// $Id$
/**
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Link�pings universitet, Department of Computer and Information Science,
 * SE-58183 Link�ping, Sweden.
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

 	@file EIMER.h
 	@brief File concerning EIMER class
 	@author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
 	Company : CEP - ARMINES (France)
 	http://www-cep.ensmp.fr/english/
 	@version 0.9 

  */

#ifndef PROBLEMMER_H
#define PROBLEMMER_H

#include "EIProblem.h"
#include "EIMERResult.h"
#include "EIConnConstrs.h"
#include "ModModelPlus.h"
#include "EIValueFiller.h"
#include "EIMERParameters.h"

/*
 * \brief Class for Target (Energy integration) problem. Target use GLPK for MILP optimization.
 */
class EIMER : public EIProblem
{
        Q_OBJECT

public:
    EIMER(Project*,ModClassTree*,MOomc*);
    EIMER(const EIMER &);
	virtual ~EIMER(void);
	virtual QString getClassName(){return "EIMER";};

    Problem* clone();
        Result* launch(ProblemConfig _config);


	QDomElement toXmlData(QDomDocument & doc);
	bool checkBeforeComp(QString & error);
	
};


#endif