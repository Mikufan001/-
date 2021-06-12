# coding:utf8
import re,itertools
import jieba

#读取文本数据
df_txt1 = open(r'G:\DownLoad\data\txt\nahan.txt', 'r').read()
df_txt2 = open(r'G:\DownLoad\data\txt\shadow.txt', 'r').read()
df_txt3 = open(r'G:\DownLoad\data\txt\yukikuni.txt', 'r').read()

#显示数据集
print('nahan:')
print(df_txt1)

print('shadow:')
print(df_txt2)

print('yukikuni:')
print(df_txt3)

#通过正则表达式来对字符串清洗
def textParse (str_doc):
    #正则过滤掉特殊符号、标点、英文、数字等
    r1 = '[a-zA-Z0-9‘！#$%&\’（）*+，—./:：;；|<=>?@、——。【】《》？“”’‘！[\\]^_{|}~]+'
    #去除空格
    r2 = '\s+'
    #去除换行符
    str_doc = re.sub(r1, '', str_doc)
    #多个空格成1个
    str_doc = re.sub(r2, '', str_doc)
    #去除换行符
    str_doc = str_doc.replace('\n', ' ')
    return str_doc

#读取文本信息
def readFile(path):
    str_doc = ""
    with open(path, 'r') as f:
        str_doc = f.read()
    return str_doc

print('nahan文本清洗结果：')
if __name__ == '__main__':
    #读取文本
    path = r'G:\DownLoad\data\txt\nahan.txt'
    str_doc = readFile(path)
    #正则清洗字符串
    word_list1 = textParse(str_doc)
    print(word_list1,'\n')

print('shadow文本清洗结果：')
if __name__ == '__main__':
    #读取文本
    path = r'G:\DownLoad\data\txt\shadow.txt'
    str_doc = readFile(path)
    #正则清洗字符串
    word_list2 = textParse(str_doc)
    print(word_list2,'\n')

print('yukikuni文本清洗结果：')
if __name__ == '__main__':
    # 读取文本
    path = r'G:\DownLoad\data\txt\yukikuni.txt'
    str_doc = readFile(path)
    # 正则清洗字符串
    word_list3 = textParse(str_doc)
    print(word_list3,'\n')

seg_list1 = jieba.cut(word_list1)
print('\nDefault Mode:'+'/'.join((seg_list1)))

seg_list2 = jieba.cut(word_list2)
print('\nDefault Mode:'+'/'.join((seg_list2)))

seg_list3 = jieba.cut(word_list2)
print('\nDefault Mode:'+'/'.join((seg_list3)))


#词频统计
from nltk import*

print('nahan的词频统计量：')
fdist = FreqDist(word_list1)
print(fdist.keys(), fdist.values())

print('shadow的词频统计量：')
fdist = FreqDist(word_list2)
print(fdist.keys(), fdist.values())

print('yukikuni的词频统计量：')
fdist = FreqDist(word_list3)
print(fdist.keys(), fdist.values())



#词云
import os
import matplotlib.pyplot as plt
from wordcloud import WordCloud

words1 = jieba.lcut(word_list1)
new_txt1 = ''.join(words1)
wordcloud = WordCloud(font_path = 'msyh.ttc').generate(new_txt1)
plt.figure()
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis('off')
plt.show()
