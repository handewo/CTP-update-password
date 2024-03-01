# CTP-update-password

*Update your CTP account password*

开发环境是：**ubuntu 18.04**

看穿式监管评测版本：**6.3.16_T1**

### Build & Run 
```bash
cd CTP-update-password

sudo cp libthostmduserapi_se.so libthosttraderapi_se.so /usr/lib/

cmake CMakeLists.txt

make

vim conf/ctp.ini  # 不需要全部填写，填写知晓的信息即可

cd bin

./ctp_update_passwd
```
