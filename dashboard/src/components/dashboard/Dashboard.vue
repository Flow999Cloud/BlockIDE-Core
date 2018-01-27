<template>
    <div class="dashboard">
        <div class="row">
            <div class="col-xs-12 col-md-12">
                <vuestic-widget :headerText="$t('transactionHistory.title')">
                    <div class="table-responsive">
                        <table class="table table-striped first-td-padding">
                            <thead>
                                <tr>
                                    <td>{{'transactionHistory.headings.type' | translate}}</td>
                                    <td>{{'transactionHistory.headings.address' | translate}}</td>
                                    <td>{{'transactionHistory.headings.dateTime' | translate}}</td>
                                    <td align="right">{{'transactionHistory.headings.amount' | translate}}</td>
                                    <td></td>
                                </tr>
                            </thead>
                            <tbody>
                                <tr>
                                    <td>Buy/Sell</td>
                                    <td>N/A</td>
                                    <td>N/A</td>
                                    <td align="right">N/A</td>
                                    <td></td>
                                </tr>
                            </tbody>
                        </table>
                    </div>
                </vuestic-widget>
            </div>
        </div>
    </div>
</template>
