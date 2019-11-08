#include<linux/init.h>
#include<linux/sched.h>
#include<linux/kernel.h>
#include<linux/module.h>

int starting_init(void){
	struct task_struct *task; // Pointer to the process which will be printed

	printk(KERN_INFO "Inserting Module into kernel");

	printk(KERN_INFO "Starting to list tasks");
	// Similiar task can be done using for_each_process macro
	for(task= &init_task; (task = next_task(task)) != &init_task;){
	printk(KERN_INFO "Process Name: %-20s Process State: %ld\t Process ID: %d\n", task->comm, task->state, task->pid);
// It points to the next task on each iteration 

}
printk(KERN_INFO "Task listing complete");
return 0;
}


void end_init(void){
	printk(KERN_INFO "Removing Process List module");
}

module_init(starting_init);
module_exit(end_init);

MODULE_DESCRIPTION("Listing Tasks Linearly");
MODULE_AUTHOR("FANUS & AMIT");

