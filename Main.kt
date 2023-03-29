class Worker(
    val name:String,
    val surname:String,
    var experience:Int,
    var salary:Int)
class Manager{
    private  var WorkerList = ArrayList<Worker>();


    fun addWorker(worker: Worker):Boolean{
        return  WorkerList.add(worker)
    }

    fun addAllWorker(worker: List<Worker>):Boolean{
        return  WorkerList.addAll(WorkerList)
    }

    fun removeWorker(worker: Worker):Boolean{
        return  WorkerList.remove(worker)
    }

    fun sumSalary():Float{
        var sum = 0f;
        for (worker in WorkerList)
        {
            sum+= worker.salary;
        }
        return sum;
    }
    fun avgSalary():Float{
        return sumSalary()/WorkerList.size;
    }
    fun printWorkersData(){
        println("----------------------------------")
         for (worker in WorkerList){
             println(worker.name)
             println(worker.surname)
             println(worker.experience)
             println("----------------------------------")
         }
    }
}

fun main(args: Array<String>) {
   val wk1 = Worker( "Adam","Smith", 10 , 20000);
   val wk2 = Worker( "Adam","Sandler", 10 , 20000);
   val wk3 = Worker( "Adam","Mirek", 10 , 20000);
   val wk4 = Worker( "Adam","Swirek", 10 , 20000);
    val ListOfWorkers = listOf<Worker>(wk1,wk2,wk3,wk4);
    val kamil = Manager();
    kamil.addAllWorker(ListOfWorkers);
    kamil.printWorkersData();
    println("AVG ${kamil.avgSalary()}")
}