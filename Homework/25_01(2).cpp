#include <iostream>  
#include <string> 


class Human
{ 
   std::string fullname;  
   int age = 18;  

   public:   
   Human() : Human("Tanya Grotter", 18) {};

   Human(const Human& other): Human(other.fullname, other.age){}

   Human(std::string fullname, int age )  
   {    
        std::cout<<"Fullname "; 
        std::cin>>(this->fullname); 
        std::cout<<"Age "; 
        std::cin>>this->age; 
   }
   
   ~Human(){} 

   std::string GetFullname() {return fullname; }; 
   int GetAge() {return age; };

   void setName(std::string fullname) { this->fullname = fullname; }
   void setAge(int age) { this->age = age; }
}; 

class Apartment
{    
     Human * people; 
     int cap;
     int fam; 


     public: 
     Apartment(){ } 
      
     Apartment(const Apartment& other) 
    {   this->people = new Human[cap];  
        this->cap=other.cap; 
        for (int i=0; i<this->fam; ++i ) 
        {
            this->people[i] = Human(other.people[i].GetFullname(), other.people[i].GetAge()); 
            this->people[i].setAge(other.people[i].GetAge());
        }
    }  

      Apartment(Human *people, int cap,  int fam) 
     {  
         this->cap = cap; 
         this->fam=fam; 
        this->people = new Human[cap];  
        for (int i=0; i<this->fam; ++i ) 
        {
            this->people[i] = people[i]; 
        }
         
        
     }     

     void add_back(Human val) 
      {   
         if ((this->fam+1) > this->cap)
          std::cout<<"No: cap = "<<this->cap<<" is too big\n"; 
         else
          { this->people[fam] = val; 
         fam++; }
     }    

     void add_to_arr(int index, Human val)
     {  
        Human *tmp = new Human[fam - index]; 
       
        for(int i=index+1; i<this->fam; ++i) 
        { 
          tmp[i]=this->people[i]; 
        } 
         this->people[index]=val; 

        for(int i=index+1; i<this->fam+1; ++i) 
        { 
         this->people[i] = tmp[i]; 
        } 

     } 

    void del(int index)     {
        if (this->fam<= index)
            std::cout<<"Nope\n";
        else{ 
        for (int j=index; j<this->fam; j++)
            this->people[index-1] = this->people[index]; 
        } 
        fam--; 
    
   } 

   void print()
   {
    for (int i=0; i<fam; ++i ){
        std::cout<<people[i]<<" "; 

        std::cout<<"\n"; 
   }
     
    int getSize()
    {return fam; }  

    int getCap() 
    {return cap; }  

    Human getHum(int i)
    {return people[i]; }

     ~Apartment(){} 

}; 



int main()
{
    Human one; 
    Human two("nick", 15); 
    Human tree("cick", 27); 
    
    Human tree_cop(tree); 
    tree_cop.setName("Kis"); 
    std::cout<<tree_cop.GetFullname()<<"\n";  

    Human *people = new Human[4] {one, two, tree, tree_cop}; 

    Apartment one_one; 
    Apartment two_two(people, 8, 4); 
    Apartment two_two_cop(two_two);  

    two_two_cop.add_to_arr(2, Human("emae", 9)); 
    two_two.del(0); 
    std::cout<<"two_two_cop\n"; 
    two_two_cop.print(); 
    std::cout<<"two_two\n"; 
    two_two.print(); 
    
}