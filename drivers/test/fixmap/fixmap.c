#include <linux/init.h>
#include <linux/module.h>
#include <asm/fixmap.h>
#include <linux/pagemap.h>

static int __init fixmap_init(void)
{
	unsigned long vaddr;
	unsigned int *swapper_addr;

	swapper_addr =(unsigned int *)swapper_pg_dir+769;

	vaddr = __fix_to_virt(FIX_WP_TEST);
	__set_fixmap(FIX_WP_TEST, __pa(&swapper_pg_dir), PAGE_READONLY);

	printk(KERN_ERR "tom fixmap module\n");
	printk(KERN_ERR "tom swapper_pg_dir+769 addr=%x value=%x\
		addr=%x value=%x\n",swapper_addr,*swapper_addr,\
		(unsigned int *)(vaddr+769*4),*((unsigned int *)(vaddr+769*4)));
	__set_fixmap(FIX_WP_TEST, __pa(&swapper_pg_dir), PAGE_READONLY);

        return 0;
}

static void __exit fixmap_exit(void)
{
	printk(KERN_ERR "tom fixmap module exit");
        return 0;
}
module_init(fixmap_init);
module_exit(fixmap_exit);
MODULE_AUTHOR("tom <tom_wei_666@163.com>");
MODULE_DESCRIPTION("fixmap test module");
MODULE_LICENSE("GPL");
