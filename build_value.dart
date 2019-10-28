
class SClass{
    
    String name;
    double year;
    int id;
    SClass(this.name,this.year,this.id){}

    

}
bool checkequality(SClass s, SClass c)
{
    if (s.name == c.name && s.id == c.id && s.year == c.year)
    {
        return true;
    }
    return false;
}

void  main(){

  bool res = checkequality(SClass("omkar",2002,1),SClass("omkar",2012,5));
  
 print(res.toString()); 
}
