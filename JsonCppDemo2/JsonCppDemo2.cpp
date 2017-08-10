// JsonCppDemo2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <json\json.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("response.txt");

	typedef Json::Reader JReader;
	typedef Json::Value	JValue;

	string strData = "{\"_id\":\"597202d328b8d7436a22e4f2\",\"roomName\":\"ѪȾȫ�������Լս\",\"startTime\":1500715800,\"deadline\":1500718200,\"password\":\"51109\",\"startMember\":[{\"nickname\":\"����δ����\",\"openid\":\"E35629495DD0C4DF5F8E03708F910FDD\",\"accountid\":\"33585611\"},{\"nickname\":\"ս��ؼ�񡣡���\",\"openid\":\"BD8198CE1351C6169955D10D5E4253DD\",\"accountid\":\"87438862\"},{\"nickname\":\"�¶�~~Ѫ��\",\"openid\":\"16C62C41CC11A1588913404448294C24\",\"accountid\":\"74435171\"},{\"nickname\":\"ţ�ƽⶾ��\",\"openid\":\"325FF7F1160CBFF10FCB30C984418EB7\",\"accountid\":\"67783223\"},{\"nickname\":\"ؿz���\\",\"openid\":\"7D8C7F672309A669AADE84D06DB0748E\",\"accountid\":\"17343844\"}],\"acceptMember\":[{\"nickname\":\"��������\",\"openid\":\"3BA40BE3CFCEB924BD86C17001E00EB3\",\"accountid\":\"27558341\"},{\"nickname\":\"������ȥ\",\"openid\":\"938944DC1A6228134C77EF415205A42D\",\"accountid\":\"27761356\"},{\"nickname\":\"ŭ��\",\"openid\":\"E0480C9B8CA18FC746ADF267CAB4A40F\",\"accountid\":\"88274843\"},{\"nickname\":\"�ƻ�_14630516940\",\"openid\":\"228984B97BC36D4B653EED26D63E857E\",\"accountid\":\"73521256\"},{\"nickname\":\"���؅d�ճ�\",\"openid\":\"C4DA3C9DEA5F6592EE2CCF9C6C992AE4\",\"accountid\":\"77863531\"}]}";

	JReader reader;
	JValue response;

	if (reader.parse(strData, response))
	{
		JValue resultList = response["result_list"];

		for (Json::ArrayIndex i = 0; i < resultList.size(); ++i)
		{
			JValue tempResult = resultList[i];

			cout << "code: " << tempResult["code"].asInt() << endl;
			cout << "message: " << tempResult["message"].asString() << endl;
			cout << "url: " << tempResult["url"].asString() << endl;

			JValue data = tempResult["data"];
			cout << "result: " << data["result"].asString() << endl;
			cout << "forbid_status: " << data["forbid_status"].asString() << endl;
			cout << "confidence: " << data["confidence"].asString() << endl;
			cout << "hot_score: " << data["hot_score"].asString() << endl;
			cout << "normal_score: " << data["normal_score"].asString() << endl;
			cout << "porn_score: " << data["porn_score"].asString() << endl;
		}
	}
	else
	{
		cout << "read error: " << reader.getFormattedErrorMessages() << endl;
	}

	ifs.close();

	system("pause");
    return 0;
}
