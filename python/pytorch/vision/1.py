#!/usr/bin/python3
#-*-encoding=utf-8-*-
__doc__ = """
torchvision包 包含了目前流行的数据集，模型结构和常用的图片转换工具。
就是说我们重设计模型的话，可以从这里开始，预训练的模型，数据集合，预处理方法
"""
## datasets

import torchvision.datasets as dset
import torchvision.transforms as transforms
cap = dset.CIFAR10(root="/data/datasets", train=True, transform=None, target_transform=None, download=True)

print('Number of samples: ', len(cap))
img, target = cap[3] # load 4th sample

print("Image Size: ", img.size())
print(target)

## models
import torchvision.models as models
# resnet18 = models.resnet18()
# alexnet = models.alexnet()
squeezenet = models.squeezenet1_0()
# densenet = models.densenet_161()


## transform


## utils
