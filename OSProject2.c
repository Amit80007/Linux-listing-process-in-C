#include<linux/init.h>
#include<linux/module.h>
#include<linux/sched.h>
#include<linux/kernel.h>

void dfs(struct task_struct *task){
	struct task_struct *child; // It points to the next child
	struct list_head *list; // Children task

	// Task State : (-1 : "Unrunnable", 0: "Runnable" , >0 : "Stopped")
	printk(KERN_INFO "Process Name: %-20s Process State: %1d \t Process ID: %d \n ", task->comm, task->state, task -> pid);

	list_for_each(list, &task -> children){
	// Loop over children processes
	child = list_entry(list, struct task_struct, sibling);
	// This child points to the next child in the list
	dfs(child);

}
}

int startListProcess(void){
	printk(KERN_INFO "Started ListProcesses using DFS Approach \n");
	dfs(&init_task);
	printk(KERN_INFO "Stopped Listing tasks \n");
	return 0;
}

void endListing(void){
	printk(KERN_INFO "Removing Listing Module");	
}

module_init(startListProcess);
module_exit(endListing);

MODULE_DESCRIPTION("Listing Tasks DFS");
MODULE_AUTHOR("FANUS & AMIT");

