data <- read.table("results.txt")

pdf("task1.pdf")

plot(data$V1, data$V2,
     type="o",
     log="x",
     xlab="n",
     ylab="Time (ms)",
     main="Scan Scaling Analysis")

dev.off()