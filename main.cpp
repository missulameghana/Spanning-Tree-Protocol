#include<iostream>

#include<vector>
#include<sstream>
#include <utility> 
#include<map> 
#include<bits/stdc++.h>
#include "bridge.h"
using namespace std;
vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); 
  string tok;
 
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
 
  return internal;
}
bool checkall(vector<bool> v){
	for(int i=0;i<v.size();i++){
		if(v[i]==false){return false;}
	}
	return true;
}
int indice(string b){
	stringstream geek(b.substr(1)); 
	int x =0;
	geek >> x;
	return x;
 	
 }
 bridge* query(vector<bridge*> bv, string name){
 	for(int i=0;i<bv.size();i++){
 		if(name==bv[i]->bridge_name){return bv[i];}
 	}
 }
 string query2(bridge* b1, bridge* b2){
 	for(int i=0;i<b1->vport.size();i++){
 		for(int j=0;j<b1->vport[i]->vbridge.size();j++){
 			if(b2->bridge_name == b1->vport[i]->vbridge[j]->bridge_name){return b1->vport[i]->port_name;}
 		}
 	}
 }
 ports* query3(vector<ports*> pv, string s){
 	for(int i=0;i<pv.size();i++){
 		if(pv[i]->port_name==s){return pv[i];}
 	}
 }
message update_mssg(vector<pair<message,bridge*>> v,string name,vector<bridge*> b){	
	bridge* hum = query(b,name);
for(int i=0;i<v.size();i++){
	if(name==v[i].second->bridge_name){
		//cout<<name<<endl;
		if(indice(v[i].first.root_bridge->bridge_name)<indice(v[i].second->best_root_bridge)){
			//cout<<"root"<<" "<<v[i].first.port->port_name<<endl;
			v[i].second->best_root_bridge = v[i].first.root_bridge->bridge_name;
			v[i].second->best_dis = v[i].first.distance + 1;
			v[i].second->parent = v[i].first.sending_bridge->bridge_name;
			v[i].second->port_parent = v[i].first.port->port_name;
			int k;
			for(int j=0;j<v[i].second->vport.size();j++){
				if(v[i].second->vport[j]->port_name==v[i].first.port->port_name){
					v[i].second->tport[j] = "RP";					
					k = j;
					break;
				}}
				for(int u=0;u<v[i].second->vport.size();u++){
					if(u!=k){
				if(v[i].second->tport[u] != "DP"){v[i].second->tport[u] = "DP";}}}
			
			
			
		}
		else if(v[i].first.distance == v[i].second->best_dis && indice(v[i].first.root_bridge->bridge_name)==indice(v[i].second->best_root_bridge)){
			//cout<<"dis equal"<<" "<<v[i].first.port->port_name<<endl;
			if(indice(v[i].second->bridge_name)>indice(v[i].first.sending_bridge->bridge_name)){
				//cout<<"we have more id"<<" "<<v[i].first.port->port_name<<endl;
				for(int j=0;j<v[i].second->vport.size();j++){
				if(v[i].second->vport[j]->port_name==v[i].first.port->port_name && v[i].second->tport[j] != "RP"){
					v[i].second->tport[j] = "NP";
				}				
			}		
			}			
			
		}
		else if(v[i].first.distance + 1 == v[i].second->best_dis && indice(v[i].first.root_bridge->bridge_name)==indice(v[i].second->best_root_bridge)){
			if(indice(v[i].first.sending_bridge->bridge_name)>indice(v[i].second->parent)){
				//cout<<"parent id less"<<" "<<v[i].first.port->port_name<<endl;
				for(int j=0;j<v[i].second->vport.size();j++){
					if(v[i].second->vport[j]->port_name==v[i].first.port->port_name && v[i].second->tport[j] != "RP"){
					v[i].second->tport[j] = "NP";
				}
				}
			}
			else if(indice(v[i].first.sending_bridge->bridge_name)==indice(v[i].second->parent)){
				//cout<<"parent id eq "<<v[i].first.port->port_name<<" "<<v[i].second->port_parent<<endl;
				if(v[i].first.port->port_name < v[i].second->port_parent ){
					//cout<<"@@@@@"<<endl;
					for(int j=0;j<v[i].second->vport.size();j++){
					if(v[i].second->vport[j]->port_name==v[i].first.port->port_name){
					v[i].second->tport[j] = "RP";
					v[i].second->parent = v[i].first.sending_bridge->bridge_name;
					
				}
				else if(v[i].second->vport[j]->port_name==v[i].second->port_parent){
					//cout<<"####"<<endl;
					v[i].second->tport[j] = "NP";	
				}
				}
				v[i].second->port_parent = v[i].first.port->port_name;
				}
				else if (v[i].first.port->port_name > v[i].second->port_parent){
					//cout<<"^^^^^"<<endl;
					for(int j=0;j<v[i].second->vport.size();j++){
					if(v[i].second->vport[j]->port_name==v[i].first.port->port_name && v[i].second->tport[j] != "RP"){
					v[i].second->tport[j] = "NP";
					//v[i].second->parent = v[i].first.sending_bridge->bridge_name;
				}
				
				}
				}
			}
			else{			
			//cout<<"parent id more"<<" "<<v[i].first.port->port_name<<endl;	
				for(int j=0;j<v[i].second->vport.size();j++){
					if(v[i].second->vport[j]->port_name==v[i].first.port->port_name){
					v[i].second->tport[j] = "RP";
					v[i].second->parent = v[i].first.sending_bridge->bridge_name;
					
				}
				else if(v[i].second->vport[j]->port_name==v[i].second->port_parent){
					v[i].second->tport[j] = "NP";	
				}
				}
				v[i].second->port_parent = v[i].first.port->port_name;
			}}			
					
	}
	

}
message m(query(b,hum->best_root_bridge),hum->best_dis,hum,hum->vport[0]);
			return m;
}

vector<pair<ports*,bridge*> > send(bridge* b){
	vector<pair<ports*,bridge*>> v;
	for(int i=0;i<b->vport.size();i++){
		
		for(int j=0;j<b->vport[i]->vbridge.size();j++){
			if(b->vport[i]->vbridge[j]->bridge_name != b->bridge_name && b->tport[i] == "DP"){
				v.push_back(make_pair(b->vport[i],b->vport[i]->vbridge[j]));
			}
		}
	}
	return v;
}

bool check(pair<string,int> m, bridge* b){
	if(m.first == b->best_root_bridge && m.second == b->best_dis){return true;}
	else{return false;}
}
bool query4(ports* p, bridge* b){
	for(int i=0;i<b->vport.size();i++){
		if(b->vport[i]->port_name == p->port_name){
			if(b->tport[i] != "NP"){return true;}
		}	
	}
	return false;
}
vector<trace> tv;
int last = 0;
void data_transfer(string h1, string h2, ports* p, bridge* b1,int t){
	//cout<<"------------------------------------------"<<endl;
	//if(mp[h2]==p){return;}
	for(int i=0;i<p->vbridge.size();i++){
		//cout<<"start"<<endl;
		if(b1 != p->vbridge[i]){
		if(query4(p,p->vbridge[i])){
			p->vbridge[i]->fwd[h1] = p;
			//cout<<"okay"<<endl;

		if(p->vbridge[i]->fwd.find(h2) == p->vbridge[i]->fwd.end()){
			for(int j=0; j<p->vbridge[i]->vport.size();j++){
				if(p->vbridge[i]->tport[j] != "NP" && p->vbridge[i]->vport[j]->port_name != p->port_name){
					trace elem(t,"r",p->vbridge[i]->bridge_name,p->port_name,p->vbridge[i]->vport[j]->port_name);
					trace elem1(t,"s",p->vbridge[i]->bridge_name,p->port_name,p->vbridge[i]->vport[j]->port_name);
					tv.push_back(elem);
					tv.push_back(elem1);
				data_transfer(h1,h2,p->vbridge[i]->vport[j],p->vbridge[i],t+1);
			}}
			
		}
		else{
			if(p->vbridge[i]->fwd[h2]->port_name != p->port_name){
				trace elem2(t,"r",p->vbridge[i]->bridge_name,p->port_name,p->vbridge[i]->fwd[h2]->port_name);
				trace elem3(t,"s",p->vbridge[i]->bridge_name,p->port_name,p->vbridge[i]->fwd[h2]->port_name);
				tv.push_back(elem2);
				tv.push_back(elem3);
			data_transfer(h1,h2,p->vbridge[i]->fwd[h2],p->vbridge[i],t+1);	
			}
			
		}
	}
}
}
	return;
}

int main(){
int tr; cin>>tr;
int n; cin>>n;
vector<bridge* > b;
vector<bool> bv(26,false);
vector<ports*> pv(26);
map<string, ports*> mp;
int no_of_ports = 0;
for(int j=0; j<n+1; j++){
	string s1;
	getline(cin,s1);
	if(j>0){
		vector<string> temp = split(s1,' ');
		string name = temp[0];
		name.pop_back();
		vector<ports* > vp;
		vector<string> tp;
		int m=0;
		for(int i=1;i<temp.size();i++){
			m++;
			if(bv[(int)temp[i][0] - 65] == false){
				bv[(int)temp[i][0] - 65] = true;
				no_of_ports ++;
				vector<bridge* > v_b;				
				ports* p=new ports(temp[i],v_b);
				pv[(int)temp[i][0] - 65]= p;
			}			
			vp.push_back(pv[(int)temp[i][0]-65]);
			tp.push_back("DP");
		}
		bridge* bu = new bridge(vp,tp,name);
		for(int i=0;i<m;i++){
			bu->vport[i]->vbridge.push_back(bu);
		}
		b.push_back(bu);
	}
	
}
//cout<<no_of_ports<<endl;
for(int j=0;j<no_of_ports;j++){
string s2;
getline(cin,s2);
if(j>=0){
	//cout<<"%%%%"<<endl;
vector<string> tmp = split(s2,' ');
tmp[0].pop_back();
//cout<<tmp[0]<<endl;
for(int k=1;k<tmp.size();k++){
	mp[tmp[k]]=query3(pv,tmp[0]);
}

}}
int trans;
cin>>trans;
//cout<<trans<<endl;
vector<pair<string,string>> ques;
for(int i=0; i<trans+1;i++){
	string s3;
	getline(cin,s3);
	if(i>0){
		//cout<<s3<<endl;
	vector<string> tp = split(s3,' ');
	ques.push_back(make_pair(tp[0],tp[1]));
	//cout<<"####"<<endl;

}}

vector<pair<message,bridge*>> v;
for(int i=0;i<n;i++){	
	for(int j=0;j<b[i]->vport.size();j++){
		message m(b[i],0,b[i],b[i]->vport[j]);
		for(int k=0;k<b[i]->vport[j]->vbridge.size();k++){
			if(b[i]->vport[j]->vbridge[k]->bridge_name!=b[i]->bridge_name){
				v.push_back(make_pair(m,b[i]->vport[j]->vbridge[k]));
			}
		}
	}
}

for(int i=0;i<b.size();i++){
	b[i]->setbest();
}
vector<bool> checkvec(n,false);
int t=0;
if(tr==1){
	for(int i=0; i<b.size();i++){
			cout<<t<<" "<<"s"<<" "<<b[i]->bridge_name<<" "<<"("<<b[i]->bridge_name<<","<<" "<<b[i]->best_dis<<","<<" "<<b[i]->bridge_name<<")"<<endl;
		}
}
t++;
while(!checkall(checkvec)){
vector<message> prtvec;
pair<string,int> v6(b[0]->best_root_bridge,b[0]->best_dis);
prtvec.push_back(update_mssg(v,b[0]->bridge_name,b));
checkvec[0] = check(v6,b[0]);

vector<pair<message,bridge*>> vec; 
vector<pair<ports*,bridge* >> v1 = send(prtvec[0].sending_bridge);		
		for(int j=0;j<v1.size();j++){
			//cout<<v1[j].first->port_name<<endl;
			prtvec[0].port = v1[j].first;
		vec.push_back(make_pair(prtvec[0],v1[j].second));}
		
	for(int i=1;i<n;i++){
		
		pair<string,int> v5(b[i]->best_root_bridge,b[i]->best_dis);
		message v4 = update_mssg(v,b[i]->bridge_name,b);

		
		vector<pair<ports*,bridge* >> v8 = send(v4.sending_bridge);	
		//cout<<v8.size()<<endl;	
		for(int j=0;j<v1.size();j++){		
		checkvec[i] = check(v5,b[i]);		
	}
		for(int j=0;j<v8.size();j++){
			//cout<<v8[j].first->port_name<<endl;
			v4.port = v8[j].first; 
			prtvec.push_back(v4);		
		vec.push_back(make_pair(v4,v8[j].second));}
	
	}
	
	if(tr==1){
		for(int i=0;i<v.size();i++){
			cout<<t<<" "<<"r"<<" "<<v[i].second->bridge_name<<" "<<"("<<v[i].first.root_bridge->bridge_name<<","<<" "<<v[i].first.distance<<","<<" "<<v[i].first.sending_bridge->bridge_name<<")"<<endl;
		}
		for(int i=0; i<vec.size();i++){
			cout<<t<<" "<<"s"<<" "<<vec[i].first.sending_bridge->bridge_name<<" "<<"("<<vec[i].first.root_bridge->bridge_name<<","<<" "<<vec[i].first.distance<<","<<" "<<vec[i].first.sending_bridge->bridge_name<<")"<<endl;
		}
	}
	t++;
	v=vec;
	
	
}
for(int i=0;i<n;i++){
	cout<<"B"<<i+1<<":"<<" ";
	
	vector<pair<string,string>> p;
	for(int k=0;k<b[i]->vport.size();k++){
		p.push_back(make_pair(b[i]->vport[k]->port_name,b[i]->tport[k]));
	}
	sort(p.begin(),p.end());
	for(int j=0;j<p.size();j++){
		if(j!=p.size()-1){
			cout<<p[j].first<<"-"<<p[j].second<<" ";
		}
		else{
			cout<<p[j].first<<"-"<<p[j].second;
		}
	
}
cout<<endl;}	
///	
int hy = b.size();
int yy = ques.size();


for(int i=0;i<yy;i++){
	//cout<<"@@@@"<<endl;
	//cout<<"SSSS"<<endl;
	//cout<<mp[ques[i].first]<<endl;
	//cout<<"KKKK"<<endl;
	data_transfer(ques[i].first,ques[i].second,mp[ques[i].first],NULL,t);
	
	if(tr==1){
		sort(tv.begin(),tv.end());
		int sz = tv.size();
		t = tv[sz-1].time;
		for(int j = last; j<sz;j++){
			cout<<tv[j].time<<" "<<tv[j].rs<<" "<<tv[j].bname<<" "<<tv[j].fromp<<"-->"<<tv[j].top<<endl;
		}
		last = sz;
	}
	//cout<<"UUU"<<endl;
	
	for(int j=0;j<hy;j++){
		cout<<"B"<<j+1<<":"<<endl;
		cout<<"HOST ID | FORWARDING PORT"<<endl;
		map<string,ports*> :: iterator it;
		vector<pair<int,string>> tempvec;
		for(it = b[j]->fwd.begin(); it != b[j]->fwd.end(); it++){
			tempvec.push_back(make_pair(indice(it->first),it->second->port_name));
			
		}
		sort(tempvec.begin(),tempvec.end());
		for(int i=0;i<tempvec.size();i++){
			cout<<"H"<<tempvec[i].first<<" | "<<tempvec[i].second<<endl;
		}

	}
	cout<<endl;
}
}	