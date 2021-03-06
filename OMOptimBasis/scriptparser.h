#ifndef SCRIPTPARSER_H
#define SCRIPTPARSER_H

#include <QFile>
#include <QString>
#include <QFileInfo>
#include <QMap>
#include <QStringList>

class ProjectBase;

class ScriptFunction
{
public:
    ScriptFunction(){};
    ScriptFunction(QString functionName,QStringList argsNames,QString description = QString());

    QString name;
    QStringList args;
    QString description;

    QString toTxt() const;
};


class ScriptParser : public QObject
{
    Q_OBJECT
public:
    ScriptParser(){_continue = true;}
    static bool parseFile(QFileInfo fileInfo,QStringList &commands,QMap<QString,QString> &options);
    static bool parseFile(const QString & text,QStringList &commands,QMap<QString,QString> &options);

    bool executeCommand(QString command);
    bool executeCommands( QStringList commands);
    virtual QString helpText(){return QString();}

public slots:
    void stop(){_continue = false;}
protected :


 protected:
    ScriptFunction findFunction(QString functionName,int nbArgs, bool &ok);

    virtual bool launchFunction(QString function, QStringList args, bool & foundFunction)=0;
    virtual void initFunctions() = 0;
     virtual QStringList functionsList();
    QMap<QString,ScriptFunction> _functions;

    bool _continue;
};

class ScriptParserOMOptimBasis : public ScriptParser
{
    Q_OBJECT
public:
    ScriptParserOMOptimBasis(ProjectBase* project);

    virtual QString helpText();

    QString annexHelpText();

public slots:
    void onProblemFinished();
protected :
    virtual bool launchFunction(QString function, QStringList args, bool & foundFunction);
    virtual void initFunctions();


    ProjectBase* _projectBase;
    bool _problemThreadFinished;
};


#endif // SCRIPTPARSER_H
