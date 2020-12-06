//
//  main.c
//  Qemu Tool Box
//
//  Created by wibus on 2020/3/29.
//  Copyright © 2020 wibus. All rights reserved.
//

#include <stdio.h>
#include <string.h>
//#include <unistd.h>

void idea(char idea[10]){
    
    int Memory; //内存大小
    int iso; //ISO镜像
    char dvd[100] = {0};
    char img[100] = {0};
    int start; //启动介质
    printf("虚拟机内存（MB）(仅输入数字): ");
    scanf("%d",&Memory);
    char* ppc = "ppc";
    if (strcmp(idea, ppc) == 0) {
        if (Memory > 2047) {
            printf("抱歉！PPC架构的系统最高内存只能为2047MB！\n");
            printf("请重新输入内存（仅输入数字）: ");
            scanf("%d",&Memory);
        }
    }
    printf("请输入或拖动你的磁盘文件路径进入此处（文件名不要过长，不要有空格）：\n");
    scanf("%s",img);
    printf("请问你需要挂载CD/DVD镜像吗？ (1=是,2=否)\n");
    //询问是否要挂载ISO镜像
    scanf("%d",&iso);
    if (iso == 1) {
        printf("请输入或拖动你的镜像文件路径进入此处（文件名不要过长，不要有空格）：\n");
        scanf("%s",dvd);
        printf("获取镜像成功！");
        printf("请问你需要从那个介质启动虚拟机？ 1=磁盘 2=镜像：");
        //询问启动介质
        scanf("%d",&start);
        if (start == 1) {
            printf("现在你可以复制以下代码进入终端并回车启动虚拟机了: \n");
            printf("➡️ qemu-system-%s -m %d -hda %s -cdrom %s -boot c\n", idea, Memory, img, dvd);
        } else {
            printf("现在你可以复制以下代码进入终端并回车启动虚拟机了: \n");
             printf("➡️ qemu-system-%s -m %d -hda %s -cdrom %s -boot d\n", idea, Memory, img, dvd);
        }
    } else {

            printf("现在你可以复制以下代码进入终端并回车启动虚拟机了: \n");
            printf("➡️ qemu-system-%s -m %d -hda %s -boot c\n", idea, Memory, img);
    }
    //END
}


int main(void) {
    
/*
 * img硬盘制作的变量
 * 硬盘名字，内存类型（GB/MB），名字，格式（vmdk...）
 */
    int hdd; //硬盘名字
    int unit; //内存大小类型
    char img_name[30] = {0}; //硬盘名字
    int imgf; //img格式选择
    
    
    printf("\n");
    printf("——————————————————\n");
    printf("  Qemu Command Box \n");
    printf("  Create by Wibus\n");
    printf("——————————————————\n");
    printf("\n");
    printf("以下是工具箱所支持的系统类型\n");
    printf("「i386」 架构系统\n");
    printf("「x86_64」架构系统\n");
    printf("「ppc」架构系统\n");
    //printf("「arm」. system by arm\n");
    //printf("「aarch」. system by aarch64\n");
    printf("「img」创建磁盘\n");
    printf("输入代号以继续... \n 🌰：如果我想要制作一个磁盘，我将会输入img \n");
    printf("Input: ");
    int i = 0;
    char chose[10] = {0};
    scanf("%s",chose);
    
    char* i386 = "i386";
    char* x86_64 = "x86_64";
    char* ppc = "ppc";
    char* img = "img";
    if (strcmp(chose, i386) == 0) {i = 1;}
    else if (strcmp(chose, x86_64) == 0){i = 2;}
    else if (strcmp(chose, ppc) == 0){i = 3;}
    else if (strcmp(chose, img) == 0){i = 6;}
    
    //选择模式
        switch(i){
            case 1:
                idea(chose);
                break;
                
            case 2:
                idea(chose);
                break;
                
            case 3:
                idea(chose);
                break;
                
                /* 未开发区域
            case 4:
                //arm架构系统
                printf("Sorry, the function is not perfect, you temporarily can not use");
                break;
                
            case 5:
                //aarch64架构系统
                printf("Sorry, the function is not perfect, you temporarily can not use");
                break;
                */
                
                
            case 6:
                //img磁盘制作
                        printf("请选择磁盘大小的单位: 1=MB 2=GB\n");
                        scanf("%d",&unit);
                        if (unit == 1) {
                            printf("磁盘大小(仅填数字！！): ");
                            scanf("%d",&hdd);
                            printf("请选择磁盘类型 1=img 2=vmdk 3=qcow2\n：");
                            //img格式选择
                            scanf("%d",&imgf);
                            switch (imgf) {
                                case 1:
                                    printf("磁盘名字(如果是中文将会自动转为拼音): ");
                                    scanf("%s", img_name);
                                    printf("Now you can open Terminal.app and copy sentence in it:\n");
                                    printf("现在你可以复制以下代码进入终端并回车创建磁盘了: \n\n");
                                    break;
                                    
                                case 2:
                                    printf("磁盘名字(如果是中文将会自动转为拼音): ");
                                    scanf("%s", img_name);
                                    printf("现在你可以复制以下代码进入终端并回车创建磁盘了: \n\n");
                                    printf("➡️ qemu-img create -f vmdk %s.vmdk %dm\n",img_name,hdd);
                                    break;
                                    
                                case 3:
                                    printf("磁盘名字(如果是中文将会自动转为拼音): ");
                                    scanf("%s", img_name);
                                    printf("现在你可以复制以下代码进入终端并回车创建磁盘了: \n\n");
                                    printf("➡️ qemu-img create -f qcow2 %s.qcow2 %dm\n",img_name,hdd);
                                    break;
                                default:
                                    printf("Program ended with exit code: -2");
                                    printf("请将错误退出代码报告给Wibus！ \n");
                                    break;
                            }
                        } else if (unit == 2) {
                          printf("磁盘大小(仅填数字！！): ");
                            scanf("%d",&hdd);
                            printf("请选择磁盘类型 1=img 2=vmdk 3=qcow2\n：");
                            //img格式选择
                            scanf("%d",&imgf);
                            switch (imgf) {
                                case 1:
                                    printf("磁盘名字(如果是中文将会自动转为拼音): ");
                                    scanf("%s", img_name);
                                    printf("现在你可以复制以下代码进入终端并回车创建磁盘了: \n\n");
                                    printf("➡️qemu-img create %s.img %dG\n",img_name,hdd);
                                    break;
                                    
                                case 2:
                                    printf("磁盘名字(如果是中文将会自动转为拼音): ");
                                    scanf("%s", img_name);
                                    printf("现在你可以复制以下代码进入终端并回车创建磁盘了: \n\n");
                                    printf("➡️qemu-img create -f vmdk %s.vmdk %dG\n",img_name,hdd);
                                    break;
                                    
                                case 3:
                                    printf("磁盘名字(如果是中文将会自动转为拼音): ");
                                    scanf("%s", img_name);
                                    printf("现在你可以复制以下代码进入终端并回车创建磁盘了: \n\n");
                                    printf("➡️qemu-img create -f qcow2 %s.qcow2 %dG\n",img_name,hdd);
                                    break;
                                    
                                default:
                                    printf("Program ended with exit code: -1");
                                    printf("请将错误退出代码报告给Wibus！ \n");
                                    break;
                            }
                        }
                break;
                
                default:
                printf("Program ended with exit code: 11 \n");
                printf("请将错误退出代码报告给Wibus！ \n");
                break;
    }
    //sleep(2);
    return 0;
}
