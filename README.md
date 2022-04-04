
# BongoToi
base on Bongo-Cat-Mver 0.1.1, add new feature Connect to bilibili live.

//////////////////////////////////////////////////////////////////////////////////////////////////

BongoToi 是一款基于开源项目 BongoCat 0.1.1 以及 blivedm 开发而来。


核心思想为使用Pipe将blivedm获得的弹幕单向传送给BongoCat。继而使得BongoCat获得与弹幕互动的功能

实际应用过程中，根据发送弹幕，激活对应的关键词（从liveRoom.json中获取），将对应的表情序号传送给BongoCat。

前置仓库清单：

- [Bongo-Cat-Mver](https://github.com/NiniQiaolima/Bongo-Cat-Mver) [branch 0.1.1]

- [blivedm](https://github.com/xfgryujk/blivedm)


//////////////////////////////////////////////////////////////////////////////////////////////////

## How to build

### Build Bongo Cat Mver
Please check Bongo-Cat-Mver branch 0.1.1.

# BongoToi 操作说明


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

1. 以下为直播间可触发的关键词：

	"哇噢"，"略略路"，"麻了"，"嗯嗯嗯"，"怎么肥四"，"大可不必"，"怎会如此",

    "你说啥捏"，"差不多了"，"给爷pa"，"生日快乐"，"我饿了"，"可爱",，"rua":"14",

    "牛蛙"，"点歌"，"mua"，"Mua"，"天下第一"，"饿饿"，"\偷偷/"

2. 更新详情：
	03.29 更新：
	- 添加新的关键词 “记仇”
	- 添加礼物互动功能。添加小心心作为示例。
	- 添加【liveRoom.json】设置文件。
      - 【room】 表示 连接的房间号。PS：短号码无效
      - 【blockList】表示 黑名单。使用uid排除部分用户。示例用户为机器人。
      - 【ReactionDMK】 表示 只要发送的弹幕含有该单词，就会激活"img\meme"文件夹中对应的表情。PS：json文件的序号比文件夹中序号大1！
      - 【ReactionGift】 表示 发送对应的礼物即可触发该表情。表情位置同样位于meme文件夹下。 PS: 注意，请务必确保礼物名与叔叔的礼物名完全一致。

	04.01 更新：
	- 增加 表情到50个
	- 修正python文件中键值错误。
	- 在bongocat中，这设置键值保护。保证当管道传输数据错误时，系统不会崩溃。
	- 偷偷生日快乐~


3. BongoCat设置：请参考[教程](https://www.bilibili.com/video/BV1d7411n71D)

    - 注意：
		1. BongoToi删除了画笔模式以及手柄模式
		2. 新增键值"liveID"为待开发内容的占位设置。即该键值无效。
		3. 键值"memeDuration"为表情的存在时间，单位为ms。


## 待开发清单：
- [x] 投喂礼物的互动。
- [x] 暴露弹幕列表于Json文件。为二次开发提供更好的条件
- [x] 暴露黑名单列表。 防止弹幕机器人对BongoToi造成阻塞
- [ ] BongoToi 播放gif。获得可视化效果
