
import pymysql as pm    #importing the module
db=pm.connect(host='localhost',user='root',password='sql@123',port=3306)
c=db.cursor()


try:  #creating the database if it does not exist
   c.execute('create database clothes')
   c.execute('use clothes')
   db.commit()
except:  #selecting the database
   c.execute('use clothes')

def createtable():   #function to create table if it does not exist
     try:
         c.execute('create table CLOTHES (ITEMCODE varchar(50),NUMBEROFTIMESRECYCLED INT(20),COTTONCONTENT INT(9),POLYESTERCONTENT INT(9),NYLONCONTENT INT(9),PLACEOFORIGIN varchar(40))')
         print('table created')
     except:
         print('table already exists')
def mainmenu():   #function to display main menu
     print('*'*100)
     print('MAIN MENU'.center(100))
     print('1.Insert into Records'.center(100))
     print('2.Display records'.center(100))
     print('3.Search record as per ITEM CODE'.center(100))
     print('4.Update record'.center(100))
     print('5.Delete Record'.center(100))
     print('*'*100)

def insertrecords(): #function to insert records into table
   A=str(input('ITEMCODE:'))
   B=int(input('NUMBER OF TIMES RECYCLED:'))
   C=int(input('COTTON CONTENT:'))
   D=int(input('POLYESTER CONTENT:'))
   F=int(input('NYLON CONTENT:'))
   E=str(input('PLACE OF ORIGIN:'))
   record=[A.upper(),B,C,D,F,E.upper()]
   cmd='insert into CLOTHES values(%s,%s,%s,%s,%s,%s)'
   c.execute(cmd,record)
   print('Records successfully inserted')
   db.commit()

def asortmenu():  #function to display records as stored
   c.execute('select * from CLOTHES')
   q='%12s %12s %12s %12s %12s %12s '
   print('='*100)
   print(q%('ITEMCODE','NUMBER OF TIMES RECYCLED','COTTON CONTENT','POLYESTER CONTENT','NYLON CONTENT','PLACE OF ORIGIN'))
   print('='*100)
   for i in c:
      for j in i:
         print('%12s' % j, end=' ')
      print()
   print('='*100)

def searchacc():  #function to search record as per Item Code
   ino=int(input('Enter Item Code:'))
   try:
      c.execute('select * from clothes where ITEMCODE=%s',ino)
      r=c.fetchall()
      for i in r:
         q='%12s %12s %12s %12s %12s %12s '
         print('='*100)
         print(q%('ITEMCODE','NUMBEROFTIMESRECYCLED','COTTON CONTENT','POLYESTER CONTENT','NYLON CONTENT','PLACEOFORIGIN'))
         print('='*100)
         for j in i:
            print('%12s' % j, end=' ')
         print()
         print('='*100)
   except:
      print('Item Code not found')

def urecord():    #function to update a record
   try:
      c.execute('select * from clothes')
      r=c.fetchall()
      a=int(input('Enter the ITEM CODE where records need to be updated:'))
      for i in r:
         i=list(i)
         if i[0]==a:
            ch=str(input('Change NUMBEROFTIMESRECYCLED?(Y/N):'))
            if ch in 'yY':
               i[1]=str(input('Enter new NUMBEROFTIMESRECYCLED:')).upper()
            ch=str(input('Change COTTON CONTENT?(Y/N):'))
            if ch in 'yY':
               i[2]=int(input('Enter new COTTON CONTENT:'))
            ch=str(input('Change POLYESTERCONTENT?(Y/N):'))
            if ch in 'yY':
               i[3]=int(input('Enter new POLYESTERCONTENT:'))
            ch=str(input('Change NYLON CONTENT?(Y/N):'))
            if ch in 'yY':
               i[4]=str(input('Enter new NYLON CONTENT:')).upper()
            ch=str(input('Change PLACEOFORIGIN?(Y/N):'))
            if ch in 'yY':
               i[5]=str(input('Enter new PLACEOFORIGIN:')).upper()
            ch=str(input('Change COUNTRY?(Y/N):'))
            if ch in 'yY':
               i[6]=str(input('Enter new COUNTRY:')).upper()
            cmd='update clothes set NUMBEROFTIMESRECYCLED=%s, COTTONCONTENT=%s, POLYESTERCONTENT=%s, NYLON CONTENT=%s, PLACEOFORIGIN=%s where ITEMCODE=%s'
            newrec=(i[1],i[2],i[3],i[4],i[5],i[6],i[0])
            c.execute(cmd,newrec)
            db.commit()
            print('Record successfully updated')
   except:
      print('ITEM CODE not found')


def drecord():    #function to delete record
   ino=int(input('Enter ITEM CODE of the record to be deleted:'))
   try:
      cmd='delete from clothes where ITEMCODE=%s'
      c.execute(cmd,ino)
      db.commit()
      print('record successfully deleted')
   except:
      print('ITEM CODE not found')
