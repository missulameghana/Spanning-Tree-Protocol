#include<vector> 
#include<string>
#include<map>
#include<sstream>
using namespace std;
class bridge;
class ports {
private: 
	
	
public:
	string port_name;
	vector<bridge* > vbridge;
	ports(string pn,vector<bridge* > vb);
	ports(){}
	// bool operator < (const ports& str) const
 //    {
 //        return (port_name < str.port_name);
 //    }

};
ports:: ports(string pn,vector<bridge* > vb){
		port_name = pn;
		vbridge = vb;
	}

class bridge{
 private:  	
 	
public: 
	string bridge_name;
 	string best_root_bridge;
 	string parent;
 	string port_parent;
 	int best_dis;
	vector<ports*> vport;
 	vector<string> tport;
 	map<string,ports*> fwd;
 	bridge(){}
	bridge(vector<ports* > vp, vector<string> tp, string s){
	setbridge(vp,tp,s);
	setbest();
}
	void setbridge(vector<ports* > vp, vector<string> tp, string s){
	vport = vp;
	tport = tp;
	bridge_name = s;
}
void setbest(){
	best_root_bridge = bridge_name;
	best_dis=0;
	parent = bridge_name;
}

	
 };
 
 class message{
private:
	
public:
	bridge* root_bridge;
	int distance;
	bridge* sending_bridge;
	ports*port;
	//message(){}
	message(bridge* Bi,int d, bridge* Bj, ports* po){
		setmessage(Bi,d,Bj,po);
	}
	void setmessage(bridge* Bi,int d, bridge* Bj,ports* po){
		root_bridge = Bi;
		distance = d;
		sending_bridge = Bj;
		port = po;
	}
};
class trace{
private:
	int ind(string b){
	stringstream geek(b.substr(1)); 
	int x =0;
	geek >> x;
	return x;
 	
 }
public:
	int time;
	string rs;
	string bname;
	string fromp;
	string top;
	trace(int t,string s1,string s2,string s3, string s4){
		time = t;
		rs = s1;
		bname = s2;
		fromp = s3;
		top = s4;
	}
	bool operator < (trace const &obj){
		if(time < obj.time){return true;}
		else if(time > obj.time){return false;}
		else{
			if(rs == "r" && obj.rs == "s"){return true;}
			else if(rs == "s" && obj.rs == "r"){return false;}
			else{
				if(ind(bname)<ind(obj.bname)){return true;}
				else{return false;}
			}
		}
	}

};