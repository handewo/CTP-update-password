# CTP-update-password

*Update your CTP account password*

开发环境是：**ubuntu 18.04**

看穿式监管评测版本：6.3.16_T1

###Build & Run 
```bash
cp libthostmduserapi_se.so libthosttraderapi_se.so /usr/lib/

cd CTP-update-password

cmake ./

make

vim conf/ctp.ini

cd bin

./ctp_update_passwd
```
