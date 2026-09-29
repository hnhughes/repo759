data <- read.table("results.txt")

pdf("task1.pdf")

plot(data$V1, data$V2,
     type="o",
     xlab="n",
     ylab="Time (ms)",
     main="Scan Scaling Analysis")

dev.off()