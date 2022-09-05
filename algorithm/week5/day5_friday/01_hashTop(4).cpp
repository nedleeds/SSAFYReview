//#include <iostream>
//#include <unordered_map>
//using namespace std;
//int cntReg, cntLogin;
//struct Status { string passwd; int isLogin = 0; };
//unordered_map<string, Status> info;
//
//void doRegister(string cmd, string id, string passwd) {
//	if (info.find(id) == info.end()) {
//		info[id].passwd = passwd;
//		info[id].isLogin = 0;
//		cntReg += 1;
//		cout << "welcome " << cntReg << '\n';
//	}
//	else {
//		cout << "reg fail\n";
//	}
//	return;
//}
//
//void doLogin(string cmd, string id, string passwd) {
//	if (info.find(id) == info.end())
//		cout << "login fail\n";
//
//	else if (info[id].passwd != passwd)
//		cout << "login fail\n";
//
//	else if (info[id].isLogin)
//		cout << "login fail\n";
//
//	else {
//		cntLogin += 1;
//		info[id].isLogin = 1;
//		cout << "login " << cntLogin << '\n';
//	}
//	return;
//}
//
//void doChange(string cmd, string id, string oldPW, string newPW) {
//	if (info.find(id) == info.end())
//		cout << "change fail\n";
//	else if (info[id].passwd != oldPW)
//		cout << "change fail\n";
//	else {
//		info[id].passwd = newPW;
//		cout << "success\n";
//	}  
//	return;
//}
//
//void doLogout(string cmd, string id) {
//	if (info.find(id) == info.end())
//		cout << "logout fail\n";
//	else if (info[id].isLogin == 0) 
//		cout << "logout fail\n";
//	else if (info[id].isLogin){
//		info[id].isLogin = 0;
//		cntLogin -= 1;
//		cout << "logout "<< cntLogin <<"\n";
//	}
//	return;
//}
//
//void doSignout(string cmd, string id) {
//	if (info.find(id) == info.end())
//		cout << "bye fail\n";
//	else if (info[id].isLogin == 0)
//		cout << "bye fail\n";
//	else {
//		info[id].isLogin = 0;
//		cntLogin -= 1;
//		cntReg -= 1;
//		info.erase(id);
//		cout << "bye " << cntReg << '\n';
//	}
//	return;
//}
//
//void doCommand(string cmd, string id) {
//	if (cmd == "reg") {
//		string passwd;
//		cin >> passwd;
//		doRegister(cmd, id, passwd);
//	}
//	else if (cmd == "login") {
//		string passwd;
//		cin >> passwd;
//		doLogin(cmd, id, passwd);
//	}
//	else if (cmd == "logout") {
//		doLogout(cmd, id);
//	}
//	else if (cmd == "change"){
//		string passwd, newPasswd;
//		cin >> passwd >> newPasswd;
//		doChange(cmd, id, passwd, newPasswd);
//	}
//	else if (cmd == "bye") {
//		doSignout(cmd, id);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	cout.tie();
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		string CMD, ID;
//		cin >> CMD >> ID;
//		doCommand(CMD, ID);
//	}
//
//	return 0;
//}