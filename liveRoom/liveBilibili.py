
import asyncio
from queue import Queue
import blivedm
import os
import time
from threading import Thread

async def run_single_client(q,id=22661866):
    """
    演示监听一个直播间
    """
    # 如果SSL验证失败就把ssl设为False，B站真的有过忘续证书的情况
    client = blivedm.BLiveClient(id, ssl=True)
    handler = MyHandler(q)
    client.add_handler(handler)

    client.start()
    try:
        await client.join()
    except KeyboardInterrupt as exc:
        print('Quit.')
        await client.stop_and_close()

class MyHandler(blivedm.BaseHandler):
    def __init__(self,q):
        self.queue = q
        self.reactionList = {"哇噢":"01",
                        "略略略":"02",
                        "麻了":"03",
                        "嗯嗯嗯":"04",
                        "怎么肥四":"05",
                        "大可不必":"06",
                        "怎会如此":"07",
                        "你说啥捏":"08",
                        "差不多了":"09",
                        "给爷pa":"10",
                        "生日快乐":"11",
                        "我饿了":"12",
                        "可爱":"13",
                        "rua":"14",
                        "牛蛙":"15",
                        "点歌":"16",
                        "mua":"17",
                        "Mua":"18",
                        "天下第一":"19",
                        "饿饿":"20",
                        "\偷偷/":"21",
                        }

    async def _on_heartbeat(self, client: blivedm.BLiveClient, message: blivedm.HeartbeatMessage):
        print(f'[{client.room_id}] 当前人气值：{message.popularity}')


    async def _on_danmaku(self, client: blivedm.BLiveClient, message: blivedm.DanmakuMessage):
        print(f'[{client.room_id}] {message.uname}：{message.msg}')
        if message.uid == 1715406684:
            return
        name = message.uname

        for k in self.reactionList.keys():
            if(k in message.msg):
                print(f'**[BongoToi] 关键词【{k}】被激活，播放表情{self.reactionList[k]}号')
                self.queue.put(self.reactionList[k])


    async def _on_gift(self, client: blivedm.BLiveClient, message: blivedm.GiftMessage):
        print(f'[{client.room_id}] {message.uname} 赠送{message.gift_name}x{message.num}'
              f' （{message.coin_type}瓜子x{message.total_coin}）')

    async def _on_buy_guard(self, client: blivedm.BLiveClient, message: blivedm.GuardBuyMessage):
        print(f'[{client.room_id}] {message.username} 购买{message.gift_name}')

    async def _on_super_chat(self, client: blivedm.BLiveClient, message: blivedm.SuperChatMessage):
        print(f'[{client.room_id}] 醒目留言 ¥{message.price} {message.uname}：{message.message}')


def live(q,id):
    # global q
    # asyncio.get_event_loop().run_until_complete(main())
    new_loop = asyncio.new_event_loop()
    asyncio.set_event_loop(new_loop)
    loop = asyncio.get_event_loop()
    loop.run_until_complete(run_single_client(q,id))

def toCPP(q):
    f = os.open(r"\\.\Pipe\BongoToi",os.O_WRONLY)
    while 1:
        # print(q.qsize())
        if q.qsize() == 0:
            msg = "0"
        else:
            msg = q.get()
        os.write(f, msg.encode())
        time.sleep(1/60)


def run(roomID):
    q = Queue(200)
    t1 = Thread(target=live, args=(q,roomID))
    t2 = Thread(target=toCPP, args=(q,))

    t1.start()
    t2.start()

    t1.join()
    t2.join()




if __name__ == '__main__':
    run(22661866)