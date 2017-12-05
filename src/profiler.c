#include "profiler.h"

const size_t transfer_lengths[4]={10,100,1000,5000};
size_t start_count=0,end_count=0;

//#define KL25Z

#ifdef KL25Z

void SysTick_Init(uint32_t ticks)
{
	SysTick->LOAD  = (uint32_t)(ticks - 1UL);
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
	                   //SysTick_CTRL_TICKINT_Msk  |
	                   SysTick_CTRL_ENABLE_Msk;
	SysTick->VAL   = 0UL;
}

void profiling_memmove_dma(uint8_t * src_addr,uint8_t * dst_addr)
{
	for(int i=0;i<4;i++)
	{
		LOG_RAW_INT(transfer_lengths[i]);LOG_RAW_STRING("Byte\n\r");
		systickzero();
		start_count=getcount();
		my_memmove_dma(src_addr,dst_addr,transfer_lengths[i]);
		end_count=getcount();
		LOG_RAW_STRING("Start Count: ");LOG_RAW_INT(start_count);LOG_RAW_STRING("\n\r");
		LOG_RAW_STRING("End Count: ");LOG_RAW_INT(end_count);LOG_RAW_STRING("\n\r");
		LOG_RAW_STRING("Count Diff: ");LOG_RAW_INT(disp_val); LOG_RAW_STRING(time_unit);
	}

}


void profiling_memset_dma(uint8_t * src_addr)
{

	for(int i=0;i<4;i++)
		{
			LOG_RAW_INT(transfer_lengths[i]);LOG_RAW_STRING("Byte\n\r");
			systickzero();
			start_count=getcount();
			my_memset_dma(src_addr,transfer_lengths[i],65);
			end_count=getcount();
			LOG_RAW_STRING("Start Count: ");LOG_RAW_INT(start_count);LOG_RAW_STRING("\n\r");
			LOG_RAW_STRING("End Count: ");LOG_RAW_INT(end_count);LOG_RAW_STRING("\n\r");
			LOG_RAW_STRING("Count Diff: ");LOG_RAW_INT(disp_val); LOG_RAW_STRING(time_unit);
		}
}

#endif

#ifndef KL25Z
size_t getcount(void)
{
	gettimeofday(&time_value,NULL);
	return time_value.tv_usec;
}
#endif

void profiling_my_memset(uint8_t * src_addr)
{
	for(int i=0;i<4;i++)
		{
			LOG_RAW_INT(transfer_lengths[i]);LOG_RAW_STRING("Byte\n\r");
			systickzero();
			start_count=getcount();
			my_memset(src_addr,transfer_lengths[i],65);
			end_count=getcount();
			LOG_RAW_STRING("Start Count: ");LOG_RAW_INT(start_count);LOG_RAW_STRING("\n\r");
			LOG_RAW_STRING("End Count: ");LOG_RAW_INT(end_count);LOG_RAW_STRING("\n\r");
			LOG_RAW_STRING("Count Diff: ");LOG_RAW_INT(disp_val); LOG_RAW_STRING(time_unit);
		}

}

void profiling_memset(uint8_t * src_addr)
{
	for(int i=0;i<4;i++)
			{
				LOG_RAW_INT(transfer_lengths[i]);LOG_RAW_STRING("Byte\n\r");
				systickzero();
				start_count=getcount();
				memset((uint8_t *)src_addr,65,transfer_lengths[i]);
				end_count=getcount();
				LOG_RAW_STRING("Start Count: ");LOG_RAW_INT(start_count);LOG_RAW_STRING("\n\r");
				LOG_RAW_STRING("End Count: ");LOG_RAW_INT(end_count);LOG_RAW_STRING("\n\r");
				LOG_RAW_STRING("Count Diff: ");LOG_RAW_INT(disp_val); LOG_RAW_STRING(time_unit);
			}


}

void profiling_my_memmove(uint8_t * src_addr,uint8_t * dst_addr)
{
	for(int i=0;i<4;i++)
		{
			LOG_RAW_INT(transfer_lengths[i]);LOG_RAW_STRING("Byte\n\r");
			systickzero();
			start_count=getcount();
			my_memmove(src_addr,dst_addr,transfer_lengths[i]);
			end_count=getcount();
			LOG_RAW_STRING("Start Count: ");LOG_RAW_INT(start_count);LOG_RAW_STRING("\n\r");
			LOG_RAW_STRING("End Count: ");LOG_RAW_INT(end_count);LOG_RAW_STRING("\n\r");
			LOG_RAW_STRING("Count Diff: ");LOG_RAW_INT(disp_val); LOG_RAW_STRING(time_unit);
		}

}

void profiling_memmove(uint8_t * src_addr,uint8_t * dst_addr)
{
	for(int i=0;i<4;i++)
			{
				LOG_RAW_INT(transfer_lengths[i]);LOG_RAW_STRING("Byte\n\r");
				systickzero();
				start_count=getcount();
				memmove((uint8_t*)src_addr,(uint8_t *)dst_addr,transfer_lengths[i]);
				end_count=getcount();
				LOG_RAW_STRING("Start Count: ");LOG_RAW_INT(start_count);LOG_RAW_STRING("\n\r");
				LOG_RAW_STRING("End Count: ");LOG_RAW_INT(end_count);LOG_RAW_STRING("\n\r");
				LOG_RAW_STRING("Count Diff: ");LOG_RAW_INT(disp_val); LOG_RAW_STRING(time_unit);
			}

}

