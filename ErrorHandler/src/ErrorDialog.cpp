#include "ErrorDialog.h"

void ErrorDialog::showError(const std::string& errorCode, ErrorHandler& handler) {
    // Mensagem básica
    std::string message = handler.getErrorMessage(errorCode);
    std::string descricao = handler.getErrorDetails(errorCode, "descricao");
    std::string detalhe = handler.getErrorDetails(errorCode, "detalhe");

    // Exibir a caixa de mensagem com o QMessageBox
    QMessageBox msgBox;
    msgBox.setWindowTitle("Erro: " + QString::fromStdString(errorCode));
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("Erro: " + QString::fromStdString(message));  // Mensagem principal
    msgBox.setInformativeText("Descrição: " + QString::fromStdString(descricao));  // Descrição
    msgBox.setDetailedText("Detalhes: " + QString::fromStdString(detalhe));  // Detalhes técnicos
    msgBox.exec();
}
