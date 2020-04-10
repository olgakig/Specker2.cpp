#include <iostream>
#include <string>
using namespace std;

class Player {

  protected:

   string name;

  public:

   Player(const string &n): name(n) {};
   virtual ~Player() {};

   virtual const string & getType() const = 0;
   virtual Move play(const State &s) = 0;

   friend ostream & operator << (ostream &out, const Player &player){

     out << player.name;

     return out;
  
   }

};

class GreedyPlayer:public Player {

  private:

   const string name1 = "Greedy";

  public:
  
   GreedyPlayer(const string &n):Player(n){}

   const string & getType() const override{

    return name1;

   } 

   Move play(const State &s) override{
     
     int heaps = s.getHeaps();
     int v[heaps];   
     int max  = v[0], m=0;

     for(int i=0;i<heaps;i++){

       v[i] = s.getCoins(i);
       
       if(v[i] > max){

        max = v[i];
        m = i;

       }

     }

     v[m] = v[m] - max;

     Move move(m, max, 0, 0);

     return move;

   }

   ~GreedyPlayer() override {}

   friend ostream & operator << (ostream &out, const GreedyPlayer    &player){

     out << player.name1 << " player " << player.name;

     return out;

   }

};

class SpartanPlayer:public Player {

  private:

   const string name2 = "Spartan";

  public:

   SpartanPlayer (const string &n):Player(n){}

   const string & getType() const override {

     return name2;

   } 

   Move play(const State &s) override{

     int heaps = s.getHeaps();
     int v[heaps];   
     int max  = v[0], m=0;

     for(int i=0;i<heaps;i++){

       v[i] = s.getCoins(i);

       if(v[i] > max){

         max = v[i];
         m = i;

       }

     }
     
     v[m] = v[m] - 1;

     Move move(m, 1, 0, 0); 

     return move;

   }

   ~SpartanPlayer() override {}

   friend ostream & operator << (ostream &out, const SpartanPlayer   &player){

     out << player.name2 << " player " << player.name;

     return out;

   }
};

class SneakyPlayer:public Player {

  private:

   const string name3 = "Sneaky";

  public:

   SneakyPlayer(const string &n):Player(n){}

   const string & getType() const override {

     return name3;

   } 

   Move play(const State &s) override{

     int heaps = s.getHeaps();
     int v[heaps];   
     int min = v[0], n=0;

     for(int i=0;i<heaps;i++){

       v[i] = s.getCoins(i);

       if(v[i] < min && v[i] > 0){

         min = v[i];
         n = i;

       }
     }
     v[n] = v[n]-min;

     Move move(n, min, 0, 0); 

     return move;

   }
   
   ~SneakyPlayer() override {}

   friend ostream & operator << (ostream &out, const SneakyPlayer    &player){

    out << player.name3 << " player " << player.name;

    return out;

   }
};

class RighteousPlayer:public Player {

  private:

   const string name4 = "Righteous";

  public:

   RighteousPlayer(const string &n):Player(n){}

   const string & getType() const override{

     return name4;

   } 

   Move play(const State &s) override {

     int heaps = s.getHeaps();
     int v[heaps];   
     int c = v[0], min = v[0], n=0, m=0;

     for(int i=0;i<heaps;i++){

       v[i] = s.getCoins(i);

       if(v[i] > c){

         c = v[i];
         m = i;

       }

       if(v[i] < min && v[i] > 0){

        min = v[i];
        n = i;

        }

     }
     v[m] = v[m]-(c/2);

     Move move(m, (c/2), n, (c/2)-1);

     return move;

   }

   ~RighteousPlayer() override{}

   friend ostream & operator << (ostream &out, const RighteousPlayer &player){

    out << player.name4 << " player " << player.name;

    return out;

   }
   
};