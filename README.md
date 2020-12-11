# 使用说明

## 免责申明
*    本源码所提供的代码仅供一般性参考，本人并不对该代码作任何保证.阅读前请先预览当地相关法律.
*    代码编写时间距离最新版已经有很长时间,应该不存在对游戏造成什么损失,因此放出来供大家学习,如若存在游戏相关漏洞代码，请及时与我联系，进行代码删除。

##  更新日志
*    1.代码为研究andorid逆向所写,最后一次完结时间:2019.09.10
*    2.代码不保证所有完成性.
*    3.一切代码都是由逆向经验所写，并不存在有官方代码泄露嫌疑;


## 注意事项
*  1.本代码可能依赖于websocket,openssl,protobuf部分可以自己改写。
*  2.代码一切为早期研究,闲余时间所写(前前后后可能花费了一个月左右时间),可能会存在很多BUG,欢迎随时完善随时提交
*  3.账号登陆需要配合腾讯Oauth进行授权(请自行研究, 有相关api接口，在此就不提供相关实现源码了)
*  4.代码时间已经较长,不保证代码可靠性.
*  5.关键参数
    - QQUser Oauth登录
    - skey Oauth登录
    - open_id 游戏Oauth id
    - androidMD5 apk包签名
*  6.分析可能需要用到工具 jd-gui,andorid-studio(用于远程调试smail),xposed相关调试模块.IDA分析一些so层加密代码
*  7.早期控制端为web端控制,代码已经废弃就不上传了.