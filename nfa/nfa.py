reg exp: NFA accepting a set of strings over {a, b} in which each string of the language contain ‘a’ as the substring.
  def stateX(n):
    if(len(n)==0):
        print("string not accepted")
          
    else: 
        if (n[0]=='a'):
            stateY(n[1:]) 
        elif (n[0]=='b'):
            stateX(n[1:])
         
def stateY(n):
    if(len(n)==0):
        print("string accepted")
          
    else:   
        if (n[0]=='a'):
            stateY(n[1:]) 
        elif (n[0]=='b'):
            stateY(n[1:]) 
      
n=input()
stateX(n)
