# MacroDeckUDP

Send UDP Msg using Macro Deck 2

使用Macro Deck 2发送UDP消息<br><br>


**This is not a MacroDeck plugin, it is just a Udp client based on Qt**

**这不是MacroDeck的插件，只是一个基于Qt的UDP客户端**<br><br>


不想专门开发一个MacroDeck的插件，所以使用取巧方式发送UDP信息。

具体逻辑就是使用MacroDeck中的Windows Utils的Start applicaton动作，以带参方式打开程序，程序会按照参数中的地址把信息发送至指定UDP服务器。<br><br>


使用方式如下：

![1.jpeg](https://picss.sunbangyan.cn/2023/12/13/745aa1d83cd4142334e16ee1d0a8db4e.jpeg)<br><br>


Argument："127.0.0.1,1001,STR,Helloworld"

127.0.0.1：UDP服务器地址。

1001：UDP服务器端口。

STR：代表发送的是字符串消息。

HEX：代表发送的是Hex消息。

Helloworld：消息。
