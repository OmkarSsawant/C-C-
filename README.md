# A Simple solution to build_value #


## simple solutions for flutter and dart for you ##
                                   
                                   
                                   
                                   
                                   
 **As we all know that dart cannot be compared two objects on the basis of values so there is a solution of flutter package named 
    build_value if you gonna use this extension only for comparing the equality of objects then prefer to use this simple  solution
    instead of making the this complicated if you dont want to mess up with your code.After all that's your choice
       the simple solution is in build_value.dart file** _(just change your feilds and use this method )_.
  
  
  
  
  ### LOGIC   :

  
  
```dart
  
           bool checkequality(SClass s, SClass c)
          {
              if (s.name == c.name && s.id == c.id && s.year == c.year)
              {
                  return true;
              }
              return false;
          }
```

### WITH OPERATOR :




```dart

          bool operator ==(dynamic c)
          {
              if (name == c.name && id == c.id && year == c.year)
              {
                  return true;
              }
              return false;
          }  

```


=============================================================================





# Here you can use this method to convert query to url form query

```dart

void main() {
  
  String search='Game Of Thrones';
  
  String modified = search.replaceAll(' ','%20');
  
  print(modified);
}


```


                                                                                                            Thank You!
