#include <common/Typedef.h>

void SystemLogArray(uint8_t *pArrayBuffer, uint16_t nArraySize)
{
	uint16_t index;
	for(index=0; index<nArraySize; index++)
	{
		printf("0x%x ", (int)pArrayBuffer[index]);
	}
	printf("\n");
}