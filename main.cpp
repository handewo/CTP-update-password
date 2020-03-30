#include "ctp_trade_handler.h"
#include "INIReader.h"
#include <iostream>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int nRequestID = 0;
    char ch[40];


    INIReader reader("../conf/ctp.ini");
    if (reader.ParseError() != 0) {
        std::cout << "Can't load config file in current directory.\n";
        return 1;
    }
    ctp_trade_handle ctp;
    ctp.CreateFtdcTraderApi();
    ctp.RegisterFront(strcpy(ch,reader.Get("td","FrontAddr","127.0.0.1:1234").c_str()));

    ctp.init();
    sleep(5);

    CThostFtdcReqAuthenticateField reqAuth = { 0 };
    strcpy(reqAuth.BrokerID, reader.Get("user","BrokerID","9999").c_str());
    strcpy(reqAuth.UserID, reader.Get("user","UserID","123456").c_str());
    strcpy(reqAuth.AuthCode, reader.Get("user","AuthCode","!@#$%^&*").c_str());
    strcpy(reqAuth.AppID, reader.Get("user","AppID","MyProgram").c_str());

    ctp.ReqAuthenticate(&reqAuth, nRequestID++);
    sleep(5);
    
    CThostFtdcReqUserLoginField reqUserLogin = { 0 };
    strcpy(reqUserLogin.BrokerID,reader.Get("user","BrokerID","9999").c_str());
    strcpy(reqUserLogin.UserID,reader.Get("user","UserID","123456").c_str());
    strcpy(reqUserLogin.Password,reader.Get("user","Password","123456").c_str());
    
    ctp.ReqUserLogin(&reqUserLogin, nRequestID++);
    sleep(5);

    CThostFtdcUserPasswordUpdateField reqUserPasswordUpdate = { 0 };
    strcpy(reqUserPasswordUpdate.BrokerID, reader.Get("user","BrokerID","9999").c_str());
    strcpy(reqUserPasswordUpdate.UserID, reader.Get("user","UserID","123456").c_str());
    strcpy(reqUserPasswordUpdate.OldPassword, reader.Get("user","Password","123456").c_str());
    strcpy(reqUserPasswordUpdate.NewPassword, reader.Get("user","SetPasswd","").c_str());

    ctp.ReqUserPasswordUpdate(&reqUserPasswordUpdate, nRequestID++);
    sleep(5);

    CThostFtdcUserLogoutField reqUserLogout = { 0 };
    strcpy(reqUserLogout.BrokerID, reader.Get("user","BrokerID","9999").c_str());
    strcpy(reqUserLogout.UserID, reader.Get("user","UserID","123456").c_str());
    ctp.ReqUserLogout(&reqUserLogout, nRequestID++);
    sleep(5);

    ctp.exit();
    return 0;
}
