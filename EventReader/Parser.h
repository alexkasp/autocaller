#pragma once
#include <map>
#include <string>



using namespace std;



class Parser
{
	string parse_incomecall(string src,string dst,string uid,string timestamp,string callid,string srctype);
	string parse_answercall(string src,string dst,string uid,string timestamp,string callid,string calltype);
	string parse_finishcall(string src,string dst,string uid,string timestamp,string callid,string callstart,string callanswer,string status,string calltype);
	string parse_transfercall(string src,string dst,string uid,string timestamp,string callid);
	string parse_initcall(string src,string dst,string uid,string timestamp,string callid);
	string parse_outcall(string src,string dst,string uid,string timestamp,string callid);
	string parse_numtype(string num);
	string format_srcdstnum(string src,string dst);
public:
	Parser(void);
	virtual ~Parser(void);
	string parsedata(map<string,string>& data);
};

