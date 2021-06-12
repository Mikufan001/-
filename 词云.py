import jieba
from wordcloud import WordCloud
f = open(r'G:\DownLoad\data\txt\nahan.txt','r')
txt = [line for line in f.readlines()]
cut_txt = []
stop = ['，','。','—','；','“','”','：','\n','！','？']
for x in txt:
    cut = jieba.lcut(x)
    for y in cut:
        if y not in stop:
            cut_txt.append(y)
cut_text = " ".join(cut_txt)
wc = WordCloud(font_path='D:\simhei.ttf',#导入字体
                   background_color='white',
                   width=1000,
                   height=800,
                   ).generate(cut_text)
wc.to_file('D:/词云.png')  # 保存图片
print("词云绘制完成！")