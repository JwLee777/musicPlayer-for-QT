#ifndef SQL_H
#define SQL_H

#include <QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>

static bool CreatConnection()
{

QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");//建库
db.setDatabaseName("mymusic.db");//给数据库起名字
if(!db.open())
{
    return false;
}
QSqlQuery query;
 query.exec(QString("create table LocalMusic (id int,MusicName varchar,FileName varchar，     primary key(id,MusicName,FileName))"));//本地音乐列表数据，把歌曲名和歌曲路径给存起来
return true;
}

#endif // SQL_H
