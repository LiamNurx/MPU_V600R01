# MPU_V600R01工程简介

## Note
FileName:			README
Author:				Liam.Nurx
Date:					2020.11

## 工程目录说明
```c
MPU_V600R01/
	- ./app/
		-- *.c			//	功能模块业务逻辑代码;
		-- *.h			//	对应 ./*.c 的头文件;
	- ./cmsis/
		-- *.s			//	芯片启动代码;
		-- *.c			//	芯片时钟初始化相关函数;
		-- *.h			//	内核访问层头文件等;
		-- ./inc/		//	外设驱动库头文件
		-- ./src/		//	外设驱动库 (hc32l13x_ddl_Rev1.8.0 Lite)
	- ./document/		//	包含此项工程所有技术/维护文档;
	- ./incdef/		
		-- *.d			//	所有目标文件 "*.o" 的文件依赖关系;
	- ./keil-project/	//	Keil MDK 工程目录
    	-- ./Listing	
    	-- ./Objects	//	keil 工程目标文件编译输出路径;
	- ./objects/		//	使用 Makefile 时各项目标文件的输出路径;
	- ./Clean.bat		//	功能: 清理执行 Makefile 后生成的中间文件;
	- ./Makefile		//	基于 Keil ARMCC 的 Makefile
	- ./Rebuild.bat		//	功能: 执行 Makefile 生成各项目标文件;
```

## 芯片管脚分配
