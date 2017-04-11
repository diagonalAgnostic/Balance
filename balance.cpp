#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <ostream>
#include <iterator>
#include <random>
#include <ctime>
#include <map>

using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::iterator;
using std::map;
using std::ifstream;
using std::ofstream;
using std::getline;

#define out cout << 
#define done << endl;

class M {
        
public:

        M(){}

        virtual ~M(){}

	void rw();
	void S(string);
        void iN();
	string s;
	
       	//void e();
        //short g;

private:
       static const vector<string> n;
        //map<string, vector<double> > m;
       //vector< vector<double> > vv;
        vector<string> i;
        vector<string> v;

};


void M::S(string i){

	this->s = i;

}//setS

void M::rw(){

   

	ifstream streamin(this->s); 
        
        string o = "new_" + this->s;
	
        ofstream streamout(o);

        bool quotes = false;

        int index = 0;
	int qCount = 0;
        int b;

        string l = "";
        string u = "";
	
        getline(streamin, l);
	
	double z = 0;	
        
        char space = ' ';
	char quote = '\"';
	char dot = '.';
	char c;
              
        string empty = " ";
        string x = "NA";
        string row = ""; 


    const char * vec[] = {"index", "deltaP", "aroonUp", "aroonDn", "aroonOsc", "trueRange", "averageTrueRange", "trueHigh", "trueLow", "Down", "MovingAverage", "Up", "percentBeta", "CCI", "V1", "EMA", "CloseVol", "V2", "V3", "High", "Mid", "Low", "Close0", "Volume", "1", "2", "e1", "shortLag3", "shortLag5", "shortLag8", "shortLag10", "shortLag12", "shortLag15", "longLag30", "longLag35", "longLag40", "longLag45", "longLag50", "longLag60", "KST1", "ksignal1", "KST2", "ksignal2", "MACD", "mSignal", "MFI", "OBV", "Dn", "Cntr", "Up", "Close1", "Close2", "XRSI", "V4", "EMA2", "V5", "EMA3", "SMA", "DEMA", "V6", "V7", "V8", "DEMA2", "fk1", "fd1", "sd1", "Close3", "fk2", "fd2", "sd2", "SMI", "SMIsignal", "fk3", "fd3", "sd3", "TDI", "DI", "TRIX", "trixSignal1", "TRIX2", "trixSignal2", "V9", "V10", "V11", "V12", "V13", "V14", "fk4", "fd4", "sd4", "Close4", "V15"};

    vector<string> m(vec, vec+92);

    for(int h = 0 ; h < m.size();  h++){

            row += m.at(h);
            if(h != (m.size() - 1)) row += ",";       
                
    }//for

         streamout << row;

         row = "";

         index = -1;
         
while(index < 9305){

        index++;

        getline(streamin, l);

        for ( b = 0; b < l.length(); b++ ){
                   
                  c = l[b];

                 // out c end

    
            if(c == quote){

                 qCount++;
                            
                }
    
            else if( (c != quote) && (c != space) ){
               
                          u+=c;
                            
                    }

            else if( ( (qCount > 1) && (c == space) )  || ( (qCount > 1) && (c == quote) ) ){


                                  qCount++;
                                  v.push_back(u);
                                  u+=",";
                                  row+=u; 
                                  u="";
   

                }//2nd else if
            
           }//for
            
            streamout << row;
            
            row = "";

      }//while

        streamin.close();
        streamout.close();
    
    out "written" done
}//rw


/*
void e(){   

        int index = 0;

        double r = 0.0;
        double nu = 0.0;
        double x = 0.0;
        double h = 0.0;
        
        std::uniform_real_distribution<double> du(0.0, 1.0);
        std::mt19937 rn;
        rn.seed(std::random_device{}()); 
            
        vector<double> q;
        vector<double> t;
        vector<double> tt;
        vector<double> p = m.find("change");

        double total; 
        int c;
        ostream streamout;
        streamout.open(o+s+f);
 
          for(auto y = v.begin(); y != v.end(); v++){

                d = m.find(*y);
                
            for(auto e = d.begin(); e != d.end(); e++, index++){
                 
                if(strcmp(p.at(index), "NA") == 0) {

                    index++;
                    e++;
                
                    }//if

                else{

                    total+=*e;
                    c++;

                  //  x = p.at(index);  
                
  //                  if(*e < 0) *e *= -1;
   //                 if(x < 0) x *= -1;
                    
    //                double rms = (sqrt(*e - x)) * (sqrt(*e - x));    
                    
    //                q.push_back(rms);
                    
    //                r = du(rn);
     //               t.push_back(r);                    
                    
      //              u = du(rn);
      //              tt.push_back(u * r);                                                
                    
                
            }//else
                                          }
        }//for e
        
//            n.insert(pair<string, vector<double> >(*y, t));//2nd layer
//            nn.insert(pair<string, vector<double> >(*y, tt));//hidden layer
            a.insert(pair<string, vector<double> >(*y, q));//1st layer  

            q.clear();
//            t.clear();//            tt.clear();
                
        }//for y   

        //neural nets built
}//e



void g(){




}//g
	
//end of functions
*/

int main(int a, char * c[]){

        //arg 0 = name of program
        //arg 1 = symbol
        //arg 2 = ipath
        //arg 3 = opath
        //arg 4 = filetype
        //arg 5 = delimiter

    if(a == 2){

        string s = c[1];              
       	M m;
	m.S(s);
       	m.rw();
	
        return 0;
    
    }//if

else {
out "error" done;
return 1;
}
}//main


