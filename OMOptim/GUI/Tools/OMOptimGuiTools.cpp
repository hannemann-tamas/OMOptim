// $Id: OMOptimGuiTools.cpp -1   $
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

     @file GuiTools.cpp
     @brief Comments for file documentation.
     @author Hubert Thieriot, hubert.thieriot@mines-paristech.fr
     Company : CEP - ARMINES (France)
     http://www-cep.ensmp.fr/english/
     @version 
*/

#include "Tools/OMOptimGuiTools.h"



ModItemsTree* OMOptimGuiTools::ModItemToTreeView(ModLoader* modLoader ,MOomc* moomc,const ModItem & modClass,QTreeView* treeView,bool showComponent)
{
    ModItemsTree* newTree = new ModItemsTree(modLoader,moomc/*,treeView*/);
    newTree->setShowComponent(showComponent);
    ModItem* root = modClass.clone();
    root->clearDescendants(); // reset root : useful if showcomponents changed.
    newTree->addChild(newTree->rootElement(),root);

    treeView->reset();
    treeView->setModel(newTree);
    return newTree;
}


QMenu* OMOptimGuiTools::newModItemPopupMenu(Project* project, const QPoint & iPoint,ModItem* selectedClass)
{
    QMenu *menu = new QMenu();
    project->setCurModItem(selectedClass);

    switch(selectedClass->getClassRestr())
    {
    case Modelica::MODEL :
        addModModelActions(menu,project,iPoint,(ModModel*)selectedClass);
    default :
            NULL;
}

    addCommonActions(menu,project,iPoint,selectedClass);

    return menu;
}

void OMOptimGuiTools::addCommonActions(QMenu* menu,Project* project, const QPoint & iPoint,ModItem* selectedModItem)
{
    //Open folder
    QAction *openFolderAct = new QAction("Open folder",menu);
    connect(openFolderAct,SIGNAL(triggered()),selectedModItem,SLOT(openMoFolder()));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/icons/Folder")), QIcon::Normal, QIcon::Off);
    openFolderAct->setIcon(icon);
    menu->addAction(openFolderAct);

    // Reload mo file
    QAction *reload = new QAction("Reload .mo file",menu);
    reload->setData(selectedModItem->filePath());
    connect(reload,SIGNAL(triggered()),project,SLOT(onReloadMOFileAsked()));
    menu->addAction(reload);

    // Edit mo file
    QAction *edit = new QAction("Open .mo file",menu);
    connect(edit,SIGNAL(triggered()),selectedModItem,SLOT(openInEditor()));
    menu->addAction(edit);
}
void OMOptimGuiTools::addModModelActions(QMenu* menu,Project* project, const QPoint & iPoint,ModModel* selectedModel)
{

    ModModelPlus* selectedModModelPlus = project->modModelPlus(selectedModel->name());

//    //Compile
//    QAction *compileModel = new QAction("Recompile model",menu);
//    connect(compileModel,SIGNAL(triggered()),selectedModModelPlus,SLOT(compile()));
//    menu->addAction(compileModel);


//    //Read variables
//    QAction *readVariables = new QAction("Read variables",menu);
//    connect(readVariables,SIGNAL(triggered()),selectedModModelPlus,SLOT(readVariables()));
//    menu->addAction(readVariables);

//    //Read connections
//    QAction *readConnections = new QAction("Read connections",menu);
//    connect(readConnections,SIGNAL(triggered()),selectedModModelPlus,SLOT(readConnections()));
//    menu->addAction(readConnections);

    //Add problem
//    QMenu *addProblemMenu = menu->addMenu("Create problem");
//    QAction *addOptimization = addProblemMenu->addAction("Optimization");
//    connect(addOptimization,SIGNAL(triggered()),project,SLOT(addNewOptimization()));
//    QAction *addOneSim = addProblemMenu->addAction("Simulation");
//    connect(addOneSim,SIGNAL(triggered()),project,SLOT(addNewOneSimulation()));
//    QAction *addEIProblem = addProblemMenu->addAction("EI");
//    connect(addEIProblem,SIGNAL(triggered()),project,SLOT(addNewEIProblem()));


//    //Set parameters
//    QAction *setParameters = new QAction("Set parameters...",menu);
//    connect(setParameters,SIGNAL(triggered()),selectedModModelPlus,SLOT(openParametersDlg()));
//    menu->addAction(setParameters);

    // Set mo dependencies
    QAction *setMoDeps = new QAction("Set .mo dependencies ...",menu);
    connect(setMoDeps,SIGNAL(triggered()),selectedModModelPlus,SLOT(openDependenciesDlg()));
    menu->addAction(setMoDeps);

//    //Select simulator
//    QActionGroup *simulator = new QActionGroup(menu);
//    simulator->setExclusive(true);
//    menu->addSeparator()->setText(tr("Simulator"));

//    ModPlusCtrl* curCtrl;
//    ModPlusCtrl::Type curType;
//    QList<ModPlusCtrl*> ctrls = selectedModModelPlus->ctrls()->values();
//    for(int i=0;i<ctrls.size();i++)
//    {
//        curCtrl = ctrls.at(i);
//        curType = selectedModModelPlus->ctrls()->key(curCtrl);
//        QAction* simAction = simulator->addAction(curCtrl->name());
//        simAction->setCheckable(true);
//        simAction->setChecked(selectedModModelPlus->ctrlType()==curType);
//        simAction->setData((int)curType);
//        menu->addAction(simAction);
//        connect(simAction,SIGNAL(triggered()),selectedModModelPlus,SLOT(setCtrlType()));
//        simulator->addAction(simAction);
//    }
//    menu->addSeparator()->setText("");

}