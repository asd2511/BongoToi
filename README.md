# BongoToi
base on Bongo-Cat-Mver 0.1.1, add new feature Connect to bilibili live.


## How to build

### Build Bongo Cat Mver
Please check Bongo-Cat-Mver branch 0.1.1.

### Build Bilibili connection
Go to liveRoom, Use Pyinstaller build a .exe file. Then copy them into Release file in BongoToi

```shell
pyinstaller -F liveBilibili.py
```

## TODO
[ ] En Tutorial


# BongoToi 操作书名

//////////////////////////////////////////////////////////////////////////////////////////////////

BongoToi 是一款基于开源项目 BongoCat 0.1.1 以及 blivedm 开发而来。


核心思想为使用Pipe将blivedm获得的弹幕单向传送给BongoCat。继而使得BongoCat获得与弹幕互动的功能



前置仓库清单：

- [Bongo-Cat-Mver](https://github.com/NiniQiaolima/Bongo-Cat-Mver) [branch 0.1.1]

- [blivedm](https://github.com/xfgryujk/blivedm)


//////////////////////////////////////////////////////////////////////////////////////////////////

## 使用说明：
- 点击BongoToi.exe即可运行。
- ！！！！！！！！！！！！！！！！！！！！！！！

	！！！！！   请不要关闭弹出的黑色对话框   ！！！！

	！！！！！！！！！！！！！！！！！！！！！！！

## 操作说明：
1. 使用 F1-F8 可切换Toi的表情
2. 使用 F9-F12 可切换Toi的饰品

## 修改说明：
1. 替换动作：

- 替换img下的文件即可替换对应动作。
- 具体位置如下：
    - F1-F8 -> 表情 -> face 文件夹
	- F9-F12 -> 饰品 -> acce 文件夹
	- 弹幕互动 -> 大表情 -> meme 文件夹
	- 其余内容请参考修改说明3中的网址。
2. 以下为直播间可触发的关键词：

	"哇噢"，"略略路"，"麻了"，"嗯嗯嗯"，"怎么肥四"，"大可不必"，"怎会如此",

    "你说啥捏"，"差不多了"，"给爷pa"，"生日快乐"，"我饿了"，"可爱",，"rua":"14",

    "牛蛙"，"点歌"，"mua"，"Mua"，"天下第一"，"饿饿"，"\偷偷/"

3. BongoCat设置：请参考[教程](https://www.bilibili.com/video/BV1d7411n71D)

    - 注意：
		1. BongoToi删除了画笔模式以及手柄模式
		2. 新增键值"liveID"为待开发内容的占位设置。即该键值无效。
		3. 键值"memeDuration"为表情的存在时间，单位为ms。


## 待开发清单：
- [ ] 投喂礼物的互动。 诚招画师。
- [ ] 暴露弹幕列表于Json文件。为二次开发提供更好的条件
- [ ] 暴露黑名单列表。 防止弹幕机器人对BongoToi造成阻塞
- [ ] BongoToi 播放gif。获得可视化效果


















