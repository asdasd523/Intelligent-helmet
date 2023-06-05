cmd_/home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/beep.o := arm-linux-gnueabihf-gcc -Wp,-MD,/home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/.beep.o.d  -nostdinc -isystem /home/qigao/arm-linux-gnueabihf-8.3/bin/../lib/gcc/arm-linux-gnueabihf/8.3.0/include -I/home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include -I./arch/arm/include/generated  -I/home/qigao/qigao/linux_learn/ebf_linux_kernel/include -I./include -I/home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi -I./arch/arm/include/generated/uapi -I/home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi -I./include/generated/uapi -include /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kconfig.h -include /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/compiler_types.h  -I/home/qigao/qigao/linux_learn/manager/LowerComp/module/beep -I/home/qigao/qigao/linux_learn/manager/LowerComp/module/beep -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -DCC_HAVE_ASM_GOTO -fno-dwarf2-cfi-asm -fno-ipa-sra -mabi=aapcs-linux -mfpu=vfp -funwind-tables -marm -Wa,-mno-warn-deprecated -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-int-in-bool-context -O2 --param=allow-store-data-races=0 -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -Wno-unused-const-variable -fomit-frame-pointer -fno-var-tracking-assignments -Wdeclaration-after-statement -Wno-pointer-sign -Wno-stringop-truncation -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -fmacro-prefix-map=/home/qigao/qigao/linux_learn/ebf_linux_kernel/= -Wno-packed-not-aligned  -DMODULE  -DKBUILD_BASENAME='"beep"' -DKBUILD_MODNAME='"beep"' -c -o /home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/.tmp_beep.o /home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/beep.c

source_/home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/beep.o := /home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/beep.c

deps_/home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/beep.o := \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kconfig.h \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/compiler-gcc.h \
    $(wildcard include/config/retpoline.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/init.h \
    $(wildcard include/config/have/arch/prel32/relocations.h) \
    $(wildcard include/config/strict/kernel/rwx.h) \
    $(wildcard include/config/strict/module/rwx.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/kasan.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/compiler_types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/int-ll64.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/int-ll64.h \
  arch/arm/include/generated/uapi/asm/bitsperlong.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/bitsperlong.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/posix_types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/stddef.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/stddef.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/posix_types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/posix_types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/barrier.h \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arm/heavy/mb.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/cpu/spectre.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/barrier.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kasan-checks.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/module.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/modules/tree/lookup.h) \
    $(wildcard include/config/livepatch.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/function/error/injection.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
    $(wildcard include/config/page/poisoning/zero.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/const.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/const.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/arch/has/refcount.h) \
    $(wildcard include/config/panic/timeout.h) \
  /home/qigao/arm-linux-gnueabihf-8.3/lib/gcc/arm-linux-gnueabihf/8.3.0/include/stdarg.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/linkage.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/stringify.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/export.h \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/module/rel/crcs.h) \
    $(wildcard include/config/trim/unused/ksyms.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/linkage.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/bitops.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/bits.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/bitops.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/typecheck.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/irqflags.h \
    $(wildcard include/config/cpu/v7m.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/arm/thumb.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/hwcap.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/hwcap.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/irqflags.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/non-atomic.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/builtin-__fls.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/builtin-__ffs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/builtin-fls.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/builtin-ffs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/ffz.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/fls64.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/sched.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/hweight.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/arch_hweight.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/const_hweight.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/lock.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/atomic.h \
    $(wildcard include/config/generic/atomic64.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/atomic.h \
    $(wildcard include/config/arm/lpae.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/prefetch.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/processor.h \
    $(wildcard include/config/have/hw/breakpoint.h) \
    $(wildcard include/config/binfmt/elf/fdpic.h) \
    $(wildcard include/config/arm/errata/754327.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/hw_breakpoint.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/unified.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/cache.h \
    $(wildcard include/config/arm/l1/cache/shift.h) \
    $(wildcard include/config/aeabi.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/cmpxchg.h \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/v6.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/cmpxchg-local.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/atomic-long.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/le.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/byteorder.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/byteorder/little_endian.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/byteorder/little_endian.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/swab.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/swab.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/swab.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/swab.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/byteorder/generic.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/printk.h \
    $(wildcard include/config/message/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/quiet.h) \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk/nmi.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kern_levels.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/kernel.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/sysinfo.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/dynamic_debug.h \
    $(wildcard include/config/jump/label.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/build_bug.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/div64.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/compiler.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/div64.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/stat.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/stat.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/stat.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/seqlock.h \
    $(wildcard include/config/debug/lock/alloc.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/preempt.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/preempt.h \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/trace/preempt/toggle.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  arch/arm/include/generated/asm/preempt.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/preempt.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/thread_info.h \
    $(wildcard include/config/thread/info/in/task.h) \
    $(wildcard include/config/have/arch/within/stack/frames.h) \
    $(wildcard include/config/hardened/usercopy.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/bug.h \
    $(wildcard include/config/bug/on/data/corruption.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/bug.h \
    $(wildcard include/config/debug/bugverbose.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/opcodes.h \
    $(wildcard include/config/cpu/endian/be32.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/restart_block.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/time64.h \
    $(wildcard include/config/64bit/time.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/math64.h \
    $(wildcard include/config/arch/supports/int128.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/time.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/crunch.h) \
    $(wildcard include/config/arm/thumbee.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/iwmmxt.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/copy/fa.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
    $(wildcard include/config/kuser/helpers.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/glue.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/pgtable-2level-types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/memory.h \
    $(wildcard include/config/need/mach/memory/h.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/xip/kernel.h) \
    $(wildcard include/config/have/tcm.h) \
    $(wildcard include/config/arm/patch/phys/virt.h) \
    $(wildcard include/config/phys/offset.h) \
    $(wildcard include/config/xip/phys/addr.h) \
    $(wildcard include/config/debug/virtual.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sizes.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pfn.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/getorder.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/bottom_half.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/spinlock_types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/spinlock_types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rwlock_types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/spinlock.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rwlock.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
    $(wildcard include/config/generic/lockbreak.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/time32.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/uidgid.h \
    $(wildcard include/config/multiuser.h) \
    $(wildcard include/config/user/ns.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/highuid.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kmod.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/umh.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/gfp.h \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/zone/device.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/cma.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/vm/pgflags.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/zsmalloc.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/page/extension.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/deferred/struct/page/init.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/wait.h \
  arch/arm/include/generated/asm/current.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/current.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/wait.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/nodemask.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/bitmap.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
    $(wildcard include/config/fortify/source.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/string.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/string.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/page-flags-layout.h \
    $(wildcard include/config/numa/balancing.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/generated/bounds.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/memory_hotplug.h \
    $(wildcard include/config/arch/has/add/pages.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/notifier.h \
    $(wildcard include/config/tree/srcu.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/errno.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/errno.h \
  arch/arm/include/generated/uapi/asm/errno.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/errno.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/errno-base.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/mutex.h \
    $(wildcard include/config/mutex/spin/on/owner.h) \
    $(wildcard include/config/debug/mutexes.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/osq_lock.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/spin/on/owner.h) \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/err.h \
  arch/arm/include/generated/asm/rwsem.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/rwsem.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/srcu.h \
    $(wildcard include/config/tiny/srcu.h) \
    $(wildcard include/config/srcu.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rcupdate.h \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/stall/common.h) \
    $(wildcard include/config/no/hz/full.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
    $(wildcard include/config/tasks/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/arch/weak/release/acquire.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rcutree.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
    $(wildcard include/config/wq/watchdog.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/timer.h \
    $(wildcard include/config/debug/objects/timers.h) \
    $(wildcard include/config/no/hz/common.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/ktime.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/jiffies.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/timex.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/timex.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/param.h \
  arch/arm/include/generated/uapi/asm/param.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/param.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/timex.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/generated/timeconst.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/timekeeping.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/timekeeping32.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rcu_segcblist.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/srcutree.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rcu_node_tree.h \
    $(wildcard include/config/rcu/fanout.h) \
    $(wildcard include/config/rcu/fanout/leaf.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/completion.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/topology.h \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/sched/smt.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/smp.h \
    $(wildcard include/config/up/late/init.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/smp.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/percpu.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/percpu.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
    $(wildcard include/config/virtualization.h) \
    $(wildcard include/config/amd/mem/encrypt.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/topology.h \
    $(wildcard include/config/arm/cpu/topology.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/arch_topology.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/topology.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sysctl.h \
    $(wildcard include/config/sysctl.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rbtree.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/sysctl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/elf.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/elf.h \
    $(wildcard include/config/vdso.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/auxvec.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/auxvec.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/vdso_datapage.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/user.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/elf.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/elf-em.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kobject.h \
    $(wildcard include/config/uevent/helper.h) \
    $(wildcard include/config/debug/kobject/release.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sysfs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kernfs.h \
    $(wildcard include/config/kernfs.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/idr.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/radix-tree.h \
    $(wildcard include/config/radix/tree/multiorder.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kobject_ns.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kref.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/refcount.h \
    $(wildcard include/config/refcount/full.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/jump_label.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rbtree_latch.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/error-injection.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/error-injection.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/tracepoint-defs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/static_key.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/module.h \
    $(wildcard include/config/arm/unwind.h) \
    $(wildcard include/config/arm/module/plts.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/fs.h \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/cgroup/writeback.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/fs/encryption.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fs/dax.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/mandatory/file/locking.h) \
    $(wildcard include/config/migration.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/wait_bit.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kdev_t.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/kdev_t.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/dcache.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rculist.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rculist_bl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/list_bl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/bit_spinlock.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/lockref.h \
    $(wildcard include/config/arch/use/cmpxchg/lockref.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/stringhash.h \
    $(wildcard include/config/dcache/word/access.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/hash.h \
    $(wildcard include/config/have/arch/hash.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/path.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/list_lru.h \
    $(wildcard include/config/memcg/kmem.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/shrinker.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/xarray.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pid.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/mm_types.h \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/userfaultfd.h) \
    $(wildcard include/config/have/arch/compat/mmap/bases.h) \
    $(wildcard include/config/membarrier.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
    $(wildcard include/config/arch/want/batched/unmap/tlb/flush.h) \
    $(wildcard include/config/hmm.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/mm_types_task.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/arch/enable/split/pmd/ptlock.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/auxvec.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/auxvec.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/uprobes.h \
    $(wildcard include/config/uprobes.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/mmu.h \
    $(wildcard include/config/cpu/has/asid.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/capability.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/capability.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/semaphore.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/fcntl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/fcntl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/fcntl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/fcntl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/fiemap.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/migrate_mode.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/percpu-rwsem.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rcuwait.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rcu_sync.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/delayed_call.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/uuid.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/uuid.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/errseq.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/ioprio.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sched.h \
    $(wildcard include/config/virt/cpu/accounting/native.h) \
    $(wildcard include/config/sched/info.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/stackprotector.h) \
    $(wildcard include/config/arch/has/scaled/cputime.h) \
    $(wildcard include/config/virt/cpu/accounting/gen.h) \
    $(wildcard include/config/posix/timers.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/ubsan.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/intel/rdt.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/rseq.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/kcov.h) \
    $(wildcard include/config/bcache.h) \
    $(wildcard include/config/vmap/stack.h) \
    $(wildcard include/config/arch/task/struct/on/stack.h) \
    $(wildcard include/config/debug/rseq.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/sched.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sem.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/sem.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/ipc.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/rhashtable-types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/ipc.h \
  arch/arm/include/generated/uapi/asm/ipcbuf.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/ipcbuf.h \
  arch/arm/include/generated/uapi/asm/sembuf.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/sembuf.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/shm.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/shm.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/hugetlb_encode.h \
  arch/arm/include/generated/uapi/asm/shmbuf.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/shmbuf.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/shmparam.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kcov.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/kcov.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/time/low/res.h) \
    $(wildcard include/config/timerfd.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/timerqueue.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
    $(wildcard include/config/have/arch/seccomp/filter.h) \
    $(wildcard include/config/seccomp/filter.h) \
    $(wildcard include/config/checkpoint/restore.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/seccomp.h \
  arch/arm/include/generated/asm/seccomp.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/seccomp.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/unistd.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/unistd.h \
    $(wildcard include/config/oabi/compat.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/unistd.h \
  arch/arm/include/generated/uapi/asm/unistd-eabi.h \
  arch/arm/include/generated/uapi/asm/unistd-common.h \
  arch/arm/include/generated/asm/unistd-nr.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/resource.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/resource.h \
  arch/arm/include/generated/uapi/asm/resource.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/resource.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/resource.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/latencytop.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sched/prio.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/signal_types.h \
    $(wildcard include/config/old/sigaction.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/signal.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/signal.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/signal.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/signal-defs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/uapi/asm/sigcontext.h \
  arch/arm/include/generated/uapi/asm/siginfo.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/siginfo.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/rseq.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sched/rt.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/iocontext.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/fs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/limits.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/ioctl.h \
  arch/arm/include/generated/uapi/asm/ioctl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/ioctl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/asm-generic/ioctl.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/percpu_counter.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/dqblk_xfs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/dqblk_v1.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/dqblk_v2.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/dqblk_qtree.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/projid.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/quota.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/nfs_fs_i.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/cdev.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/generic/msi/irq/domain.h) \
    $(wildcard include/config/pinctrl.h) \
    $(wildcard include/config/generic/msi/irq.h) \
    $(wildcard include/config/dma/cma.h) \
    $(wildcard include/config/of.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/ioport.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/klist.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pm.h \
    $(wildcard include/config/vt/console/sleep.h) \
    $(wildcard include/config/pm.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/ratelimit.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/overflow.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/device.h \
    $(wildcard include/config/dmabounce.h) \
    $(wildcard include/config/iommu/api.h) \
    $(wildcard include/config/arm/dma/use/iommu.h) \
    $(wildcard include/config/xen.h) \
    $(wildcard include/config/arch/omap.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pm_wakeup.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/uaccess.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/uaccess.h \
    $(wildcard include/config/cpu/sw/domain/pan.h) \
    $(wildcard include/config/cpu/use/domains.h) \
    $(wildcard include/config/uaccess/with/memcpy.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
    $(wildcard include/config/cpu/cp15/mmu.h) \
  arch/arm/include/generated/asm/extable.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/extable.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/delay.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/delay.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/ide.h \
    $(wildcard include/config/blk/dev/ideacpi.h) \
    $(wildcard include/config/ide/proc/fs.h) \
    $(wildcard include/config/idepci/pcibus/order.h) \
    $(wildcard include/config/blk/dev/idedma/pci.h) \
    $(wildcard include/config/blk/dev/offboard.h) \
    $(wildcard include/config/blk/dev/idedma.h) \
    $(wildcard include/config/blk/dev/idedma/sff.h) \
    $(wildcard include/config/ide/xfer/mode.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/ata.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/blkdev.h \
    $(wildcard include/config/blk/wbt.h) \
    $(wildcard include/config/blk/dev/throttling/low.h) \
    $(wildcard include/config/blk/dev/integrity.h) \
    $(wildcard include/config/blk/dev/zoned.h) \
    $(wildcard include/config/blk/dev/bsg.h) \
    $(wildcard include/config/blk/dev/throttling.h) \
    $(wildcard include/config/blk/debug/fs.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sched/clock.h \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/irq/time/accounting.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/major.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/genhd.h \
    $(wildcard include/config/fail/make/request.h) \
    $(wildcard include/config/solaris/x86/partition.h) \
    $(wildcard include/config/bsd/disklabel.h) \
    $(wildcard include/config/unixware/disklabel.h) \
    $(wildcard include/config/minix/subpartition.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/slab.h \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/have/hardened/usercopy/allocator.h) \
    $(wildcard include/config/slab.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/kasan.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/percpu-refcount.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/blk_types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/bvec.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pagemap.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/mm.h \
    $(wildcard include/config/have/arch/mmap/rnd/bits.h) \
    $(wildcard include/config/have/arch/mmap/rnd/compat/bits.h) \
    $(wildcard include/config/mem/soft/dirty.h) \
    $(wildcard include/config/arch/uses/high/vma/flags.h) \
    $(wildcard include/config/arch/has/pkeys.h) \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/x86.h) \
    $(wildcard include/config/parisc.h) \
    $(wildcard include/config/sparc64.h) \
    $(wildcard include/config/x86/intel/mpx.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/dev/pagemap/ops.h) \
    $(wildcard include/config/shmem.h) \
    $(wildcard include/config/have/memblock.h) \
    $(wildcard include/config/debug/vm/rb.h) \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/hugetlbfs.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/range.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/page_ext.h \
    $(wildcard include/config/idle/page/tracking.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/stacktrace.h \
    $(wildcard include/config/stacktrace.h) \
    $(wildcard include/config/user/stacktrace/support.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/stackdepot.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/page_ref.h \
    $(wildcard include/config/debug/page/ref.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/page-flags.h \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/thp/swap.h) \
    $(wildcard include/config/ksm.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/memremap.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/pgtable.h \
    $(wildcard include/config/highpte.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/proc-fns.h \
    $(wildcard include/config/big/little.h) \
    $(wildcard include/config/harden/branch/predictor.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/glue-proc.h \
    $(wildcard include/config/cpu/arm7tdmi.h) \
    $(wildcard include/config/cpu/arm720t.h) \
    $(wildcard include/config/cpu/arm740t.h) \
    $(wildcard include/config/cpu/arm9tdmi.h) \
    $(wildcard include/config/cpu/arm920t.h) \
    $(wildcard include/config/cpu/arm922t.h) \
    $(wildcard include/config/cpu/arm925t.h) \
    $(wildcard include/config/cpu/arm926t.h) \
    $(wildcard include/config/cpu/arm940t.h) \
    $(wildcard include/config/cpu/arm946e.h) \
    $(wildcard include/config/cpu/arm1020.h) \
    $(wildcard include/config/cpu/arm1020e.h) \
    $(wildcard include/config/cpu/arm1022.h) \
    $(wildcard include/config/cpu/arm1026.h) \
    $(wildcard include/config/cpu/mohawk.h) \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/cpu/v6k.h) \
    $(wildcard include/config/cpu/pj4b.h) \
    $(wildcard include/config/cpu/v7.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/pgtable-nopud.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/pgtable-nop4d-hack.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/5level-fixup.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/pgtable-hwdef.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/pgtable-2level-hwdef.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/tlbflush.h \
    $(wildcard include/config/smp/on/up.h) \
    $(wildcard include/config/cpu/tlb/v4wt.h) \
    $(wildcard include/config/cpu/tlb/fa.h) \
    $(wildcard include/config/cpu/tlb/v4wbi.h) \
    $(wildcard include/config/cpu/tlb/feroceon.h) \
    $(wildcard include/config/cpu/tlb/v4wb.h) \
    $(wildcard include/config/cpu/tlb/v6.h) \
    $(wildcard include/config/cpu/tlb/v7.h) \
    $(wildcard include/config/arm/errata/720789.h) \
    $(wildcard include/config/arm/errata/798181.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/pgtable-2level.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/pgtable.h \
    $(wildcard include/config/pgtable/levels.h) \
    $(wildcard include/config/have/arch/transparent/hugepage/pud.h) \
    $(wildcard include/config/have/arch/soft/dirty.h) \
    $(wildcard include/config/arch/enable/thp/migration.h) \
    $(wildcard include/config/have/arch/huge/vmap.h) \
    $(wildcard include/config/x86/espfix64.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/huge_mm.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sched/coredump.h \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
    $(wildcard include/config/debug/tlbflush.h) \
    $(wildcard include/config/debug/vm/vmacache.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/vm_event_item.h \
    $(wildcard include/config/memory/balloon.h) \
    $(wildcard include/config/balloon/compaction.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/highmem.h \
    $(wildcard include/config/x86/32.h) \
    $(wildcard include/config/debug/highmem.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/hardirq.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
    $(wildcard include/config/hwlat/tracer.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/vtime.h \
    $(wildcard include/config/virt/cpu/accounting.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/context_tracking_state.h \
    $(wildcard include/config/context/tracking.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/hardirq.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/irq.h \
    $(wildcard include/config/sparse/irq.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/irq_cpustat.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/cacheflush.h \
    $(wildcard include/config/arm/errata/411920.h) \
    $(wildcard include/config/cpu/cache/vipt.h) \
    $(wildcard include/config/outer/cache.h) \
    $(wildcard include/config/frame/pointer.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/glue-cache.h \
    $(wildcard include/config/cpu/cache/v4.h) \
    $(wildcard include/config/cpu/cache/v4wb.h) \
    $(wildcard include/config/cache/b15/rac.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/cachetype.h \
    $(wildcard include/config/cpu/cache/vivt.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/optee.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/kmap_types.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/highmem.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/hugetlb_inline.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/backing-dev-defs.h \
    $(wildcard include/config/debug/fs.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/flex_proportions.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/mempool.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/bio.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/io.h \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/need/mach/io/h.h) \
    $(wildcard include/config/pcmcia/soc/common.h) \
    $(wildcard include/config/isa.h) \
    $(wildcard include/config/pccard.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/xen/xen.h \
    $(wildcard include/config/xen/pvh.h) \
    $(wildcard include/config/xen/dom0.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/io.h \
    $(wildcard include/config/generic/iomap.h) \
    $(wildcard include/config/has/ioport/map.h) \
    $(wildcard include/config/virt/to/bus.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/logic_pio.h \
    $(wildcard include/config/indirect/pio.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/fwnode.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/vmalloc.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/bsg.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/bsg.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/scatterlist.h \
    $(wildcard include/config/need/sg/dma/length.h) \
    $(wildcard include/config/debug/sg.h) \
    $(wildcard include/config/sgl/alloc.h) \
    $(wildcard include/config/arch/has/sg/chain.h) \
    $(wildcard include/config/sg/pool.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/blkzoned.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/elevator.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/hashtable.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/proc_fs.h \
    $(wildcard include/config/proc/fs.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/interrupt.h \
    $(wildcard include/config/irq/forced/threading.h) \
    $(wildcard include/config/generic/irq/probe.h) \
    $(wildcard include/config/irq/timings.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/irqreturn.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/irqnr.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/irqnr.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/sections.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/sections.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pci.h \
    $(wildcard include/config/pci/iov.h) \
    $(wildcard include/config/pcieaer.h) \
    $(wildcard include/config/pcieaspm.h) \
    $(wildcard include/config/hotplug/pci/pcie.h) \
    $(wildcard include/config/pcie/ptm.h) \
    $(wildcard include/config/pci/msi.h) \
    $(wildcard include/config/pci/ats.h) \
    $(wildcard include/config/pci/pri.h) \
    $(wildcard include/config/pci/pasid.h) \
    $(wildcard include/config/pci/domains/generic.h) \
    $(wildcard include/config/pcieportbus.h) \
    $(wildcard include/config/pcie/ecrc.h) \
    $(wildcard include/config/pci/domains.h) \
    $(wildcard include/config/acpi.h) \
    $(wildcard include/config/pci/quirks.h) \
    $(wildcard include/config/hibernate/callbacks.h) \
    $(wildcard include/config/pci/mmconfig.h) \
    $(wildcard include/config/acpi/mcfg.h) \
    $(wildcard include/config/hotplug/pci.h) \
    $(wildcard include/config/eeh.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/mod_devicetable.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/io.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/resource_ext.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/pci.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/pci_regs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pci_ids.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/pci.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/mach/pci.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pci-dma-compat.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/dma-mapping.h \
    $(wildcard include/config/have/generic/dma/coherent.h) \
    $(wildcard include/config/has/dma.h) \
    $(wildcard include/config/arch/has/dma/set/coherent/mask.h) \
    $(wildcard include/config/need/dma/map/state.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/dma-debug.h \
    $(wildcard include/config/dma/api/debug.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/dma-direction.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/mem_encrypt.h \
    $(wildcard include/config/arch/has/mem/encrypt.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/dma-mapping.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/xen/hypervisor.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/xen/arm/hypervisor.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/cdrom.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/scsi/scsi_common.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/scsi/scsi_proto.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/uapi/linux/cdrom.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/scsi/scsi_cmnd.h \
    $(wildcard include/config/scsi/dma.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/t10-pi.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/scsi/scsi_device.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/scsi/scsi.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/scsi/scsi_request.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/blk-mq.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sbitmap.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/gpio.h \
    $(wildcard include/config/gpiolib.h) \
    $(wildcard include/config/arch/have/custom/gpio/h.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/gpio.h \
    $(wildcard include/config/arch/nr/gpio.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/gpio.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/of.h \
    $(wildcard include/config/of/dynamic.h) \
    $(wildcard include/config/sparc.h) \
    $(wildcard include/config/of/promtree.h) \
    $(wildcard include/config/of/kobj.h) \
    $(wildcard include/config/of/numa.h) \
    $(wildcard include/config/of/overlay.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/property.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/gpio/driver.h \
    $(wildcard include/config/gpiolib/irqchip.h) \
    $(wildcard include/config/gpio/generic.h) \
    $(wildcard include/config/of/gpio.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/irq.h \
    $(wildcard include/config/generic/irq/effective/aff/mask.h) \
    $(wildcard include/config/generic/irq/ipi.h) \
    $(wildcard include/config/irq/domain/hierarchy.h) \
    $(wildcard include/config/generic/irq/migration.h) \
    $(wildcard include/config/generic/pending/irq.h) \
    $(wildcard include/config/hardirqs/sw/resend.h) \
    $(wildcard include/config/generic/irq/legacy/alloc/hwirq.h) \
    $(wildcard include/config/generic/irq/legacy.h) \
    $(wildcard include/config/generic/irq/multi/handler.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/irqhandler.h \
  arch/arm/include/generated/asm/irq_regs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/asm-generic/irq_regs.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/irqdesc.h \
    $(wildcard include/config/irq/preflow/fasteoi.h) \
    $(wildcard include/config/generic/irq/debugfs.h) \
    $(wildcard include/config/handle/domain/irq.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/hw_irq.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/irqchip/chained_irq.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/irqdomain.h \
    $(wildcard include/config/irq/domain.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pinctrl/pinctrl.h \
    $(wildcard include/config/generic/pinconf.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/seq_file.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
    $(wildcard include/config/keys.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/key.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/assoc_array.h \
    $(wildcard include/config/associative/array.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/sched/user.h \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/bpf/syscall.h) \
    $(wildcard include/config/net.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pinctrl/pinctrl-state.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pinctrl/devinfo.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pinctrl/consumer.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pinctrl/pinconf-generic.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/pinctrl/machine.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/gpio/consumer.h \
    $(wildcard include/config/gpio/sysfs.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/arch/arm/include/asm/mach/map.h \
    $(wildcard include/config/debug/ll.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/of_address.h \
    $(wildcard include/config/of/address.h) \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/of_gpio.h \
  /home/qigao/qigao/linux_learn/ebf_linux_kernel/include/linux/platform_device.h \
    $(wildcard include/config/suspend.h) \

/home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/beep.o: $(deps_/home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/beep.o)

$(deps_/home/qigao/qigao/linux_learn/manager/LowerComp/module/beep/beep.o):
