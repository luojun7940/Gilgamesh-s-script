使用说明：<br>
直接下载zip文件和git clone都可以。<br>
点击.exe文件即可开始。
因为大量使用system函数会被杀毒软件认为是木马，给个信任文件就行，不需要关闭杀毒软件。。。
但是系统自带的杀毒不会识别为木马。
如果信不过可以自己编译或者自己写。


如果你不需要开发部分可以把源码删去（即删除所有.cpp和.h文件）。<br>


第一需要完成地址的设置：<br>
1、打开address.txt文件。<br>


2、第一行填模拟器的地址；<br>
  模拟器地址可以右键你要使用的模拟器的快捷方式，点击属性，在目标那一行看到;<br>

  
3、第二行是adb地址；可以将模拟器地址后面改为adb.exe得到；<br>
例：模拟器地址"D:\Game\MuMu Player 12\shell\MuMuPlayer.exe" -v 3  <br>
那么adb地址就是"D:\Game\MuMu Player 12\shell\adb.exe"；<br>
注意添加双引号。<br>


4、第三行是模拟器的序列号，可以通过查询知道模拟器序列号前半部分，后半部分可以通过多开器或模拟器设置查询。mumu模拟器序列号一般为“127.0.0.1:xxxxx”,后半部分可以通过mumu多开器的adb按钮查询。<br><br><br>
第二填写脚本的任务<br>
1、打开Settings.txt文件，输入任务格式。


下面是任务示例，但实际测试过的只有讨伐任务。<br>
有些任务可以添加后缀使其目标更清晰。


//邮箱<br>
//讨伐<br>
//冒险<br>
//招募<br>
//探索<br>
//派驻<br>
//领取AP<br>
//联盟：<br>
//领取任务<br>
//活动（仅消耗ap,boss关因为有单人关和多人关不一样所以没有写）<br>
//讨伐:常驻；火；VERY HARD；满血；<br>
//联盟:1x（1x表示赞助1x10万，其他同理）；<br>
//联盟：不赞助<br>
(前面添加"//"表示不执行)；<br>


  
